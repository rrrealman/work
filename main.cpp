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

class Recorder : public QCoreApplication
{
public:
    Recorder(int argc, char **argv);
    ~Recorder();
private:
    void onBusMessage(const QGst::MessagePtr & message);
private:
    QGst::PipelinePtr pipeline1, pipeline2, pipeline3;
};

Recorder::Recorder(int argc, char **argv)
    : QCoreApplication(argc, argv)
{
    QGst::init(&argc, &argv);
    if (argc <= 1)
    {
        std::cerr << "Usage: " << argv[0] << " <media_file>" << std::endl;
        std::exit(1);
    }

    /* source pipeline 1 */
    QString pipe1Descr = QString("rtspsrc location=\"%1\" ! "
                                 "rtph264depay ! "
                                 "mpegtsmux ! "
                                 "filesink location=\"%2\"").arg(argv[1], argv[2]);

    QString pipe2Descr = QString("rtspsrc location=\"%1\" ! "
                                 "rtph264depay ! "
                                 "mpegtsmux ! "
                                 "filesink location=\"%2\"").arg(argv[3], argv[4]);

    QString pipe3Descr = QString("rtspsrc location=\"%1\" ! "
                                 "rtph264depay ! "
                                 "mpegtsmux ! "
                                 "filesink location=\"%2\"").arg(argv[5], argv[6]);

    pipeline1 = QGst::Parse::launch(pipe1Descr).dynamicCast<QGst::Pipeline>();
    QGlib::connect(pipeline1->bus(), "message::error", this, &Recorder::onBusMessage);
    pipeline1->bus()->addSignalWatch();

    pipeline2 = QGst::Parse::launch(pipe2Descr).dynamicCast<QGst::Pipeline>();
    QGlib::connect(pipeline2->bus(), "message::error", this, &Recorder::onBusMessage);
    pipeline2->bus()->addSignalWatch();

    pipeline3 = QGst::Parse::launch(pipe3Descr).dynamicCast<QGst::Pipeline>();
    QGlib::connect(pipeline3->bus(), "message::error", this, &Recorder::onBusMessage);
    pipeline3->bus()->addSignalWatch();

    /* start playing */
    pipeline1->setState(QGst::StatePlaying);
    pipeline2->setState(QGst::StatePlaying);
    pipeline3->setState(QGst::StatePlaying);
}

Recorder::~Recorder()
{
    pipeline1->setState(QGst::StateNull);
    pipeline1.clear();
    pipeline2->setState(QGst::StateNull);
    pipeline2.clear();
    pipeline3->setState(QGst::StateNull);
    pipeline3.clear();
}

void Recorder::onBusMessage(const QGst::MessagePtr & message)
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
    Recorder r(argc, argv);
    return r.exec();
}
