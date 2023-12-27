#ifndef PLAYER_H
#define PLAYER_H
#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QPropertyAnimation>
#include "videobutton.h"

class PlayerWidget : public QWidget
{
    Q_OBJECT

    QMediaPlayer* multiPlayer;
    QVideoWidget* videoWidget;
    QAudioOutput* audioOutput;
    QPropertyAnimation *animation;

    buttonWidget* btnWidget;
    QSlider* player_slider;
    QLabel* playerTime_label;
    QLabel* totalTime_label;
    QPushButton *return_btn;
    QPushButton *share_btn;
    QString totalFormattedTime;
    QString currentFormattedTime;

    bool fullscreen;
    void Init();

signals:
    void back(QWidget *close);

public:
    PlayerWidget(QWidget *parent = nullptr);
    ~PlayerWidget();

protected slots:
    void voiceclick(int voice);
    void voicechange(int voice);

    void playclick();
    void stopclick();
    void aheadclick();
    void backclick();
    void fullscreenClick();
    void returnclick();

    void getduration(qint64 duration);

    void VideoPosChange(qint64 position);

    void ProgressChange(int pos);

    void SpeedChange(int value);

    void SetResource(QString resource,QPalette currentPal,QSize currentPageSize,int x, int y);

};
#endif // PLAYER_H
