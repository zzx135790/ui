#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QAudioOutput>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>
#include <QTime>

class Widget : public QWidget
{
    Q_OBJECT

    QMediaPlayer* multiPlayer;
    QVideoWidget* videoWidget;
    QAudioOutput* audioOutput;

    QPushButton* voice_button;
    QSlider* voice_slider;
    int voice_data;

    QPushButton* speed_button;
    QLabel* speed_label;
    QSlider* speed_slider;

    QSlider* player_slider;

    QPushButton* paly_button;
    QPushButton* pause_button;
    QPushButton* back_button;
    QPushButton* ahead_button;
    QPushButton* selectFile_button;
    QPushButton* fullscreen_button;
    bool fullscreen;

    QLabel* playerTime_label;

    QHBoxLayout* hlayout1;
    QHBoxLayout* hlayout2;
    QHBoxLayout* hlayout3;

    QString resource;

    QString totalFormattedTime;
    QString currentFormattedTime;


    void Init();

    void ButtonStyleSet(QPushButton* button, QString IconPath);

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

    void SetResource();

};
#endif // WIDGET_H
