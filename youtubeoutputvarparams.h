#ifndef YOUTUBEOUTPUTVARPARAMS_H
#define YOUTUBEOUTPUTVARPARAMS_H

#include <QWidget>

namespace Ui {
class YoutubeOutputVarParams;
}

class YoutubeOutputVarParams : public QWidget
{
    Q_OBJECT

public:
    explicit YoutubeOutputVarParams(QWidget *parent = 0);
    ~YoutubeOutputVarParams();

private:
    Ui::YoutubeOutputVarParams *ui;
};

#endif // YOUTUBEOUTPUTVARPARAMS_H
