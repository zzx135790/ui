#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>
#include <QPropertyAnimation>
#include "buttonwidget.h"

class Widget : public QWidget
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

    QString totalFormattedTime;
    QString currentFormattedTime;

    int voice_data;
    bool fullscreen;

    void Init();


public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

protected slots:
    void voiceclick();
    void voicechange(int voice);

    void playclick();
    void stopclick();
    void aheadclick();
    void backclick();
    void fullscreenClick();

    void getduration(qint64 duration);

    void VideoPosChange(qint64 position);

    void ProgressChange(int pos);

    void SpeedChange(int value);

    void SetResource(QString resouce);

};
#endif // WIDGET_H
