#include <iostream>
#include <QCoreApplication>
#include <QGlib/Error>
#include <QGlib/Connect>
#include <QGst/Init>
#include <QGst/Bus>
#include <QGst/Pipeline>
#include <QGst/Parse>
#include <QGst/Message>
#include <QGst/Utils/ApplicationSink>
#include <QGst/Utils/ApplicationSource>
#include <QGst/Event>

class MySink : public QGst::Utils::ApplicationSink
{
public:
    MySink(QGst::Utils::ApplicationSource *src) : QGst::Utils::ApplicationSink(), m_src(src) {}
protected:
    virtual void eos()
    {
        m_src->endOfStream();
    }
    virtual QGst::FlowReturn newSample()
    {
        QGst::SamplePtr sample = pullSample();
        m_src->pushBuffer(sample->buffer());
        return QGst::FlowOk;
    }
private:
    QGst::Utils::ApplicationSource *m_src;
};

class Player : public QCoreApplication
{
public:
    Player(int argc, char **argv);
    ~Player();
private:
    void onBusMessage(const QGst::MessagePtr & message);
private:
    QGst::Utils::ApplicationSource m_src;
    MySink m_sink;
    QGst::PipelinePtr pipeline1;
};

Player::Player(int argc, char **argv)
    : QCoreApplication(argc, argv), m_sink(&m_src)
{
    QGst::init(&argc, &argv);
    if (argc <= 1)
    {
        std::cerr << "Usage: " << argv[0] << " <media_file>" << std::endl;
        std::exit(1);
    }

    const char *caps = "video/x-h264, format=(string)avc,"
                       "width=(int)360, height=(int)360";

    /* source pipeline */
    QString pipe1Descr = QString("rtspsrc location=\"%1\" ! "
                                 "rtph264depay ! "
                                 "mpegtsmux ! "
                                 "filesink location=\"%2\"").arg(argv[1], argv[2]);

//    QString pipe1Descr = QString("rtspsrc location=\"%1\" ! "
//                                 "rtph264depay ! "
//                                 "h264parse ! "
//                                 "avdec_h264 ! "
//                                 "videoconvert ! "
//                                 "videoscale ! "
//                                 "xvimagesink").arg(argv[1]); //qt5videosink

    pipeline1 = QGst::Parse::launch(pipe1Descr).dynamicCast<QGst::Pipeline>();
    m_sink.setElement(pipeline1->getElementByName("mysink"));
    QGlib::connect(pipeline1->bus(), "message::error", this, &Player::onBusMessage);
    pipeline1->bus()->addSignalWatch();

    /* start playing */
    pipeline1->setState(QGst::StatePlaying);
}

Player::~Player()
{
//    pipeline1->sendEvent(QGst::EosEvent::create());
    pipeline1->setState(QGst::StateNull);
    pipeline1.clear();
}

void Player::onBusMessage(const QGst::MessagePtr & message)
{
    switch (message->type()) {
        case QGst::MessageEos:
            quit();
            break;
        case QGst::MessageError:
            qCritical() << message.staticCast<QGst::ErrorMessage>()->error();
            break;
        default:
            break;
    }
}

int main(int argc, char **argv)
{
    Player p(argc, argv);

    return p.exec();
}
