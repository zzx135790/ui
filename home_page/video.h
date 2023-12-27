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

// Player component and backend player
class PlayerWidget : public QWidget
{
    Q_OBJECT
    // Player
    QMediaPlayer* multiPlayer;
    // Playback screen
    QVideoWidget* videoWidget;
    //    QAudioOutput* audioOutput;
    //    QPropertyAnimation *animation;

    // Button components
    buttonWidget* btnWidget;

    // Progress bar
    QSlider* player_slider;
    // Running time label
    QLabel* playerTime_label;
    // Total time label
    QLabel* totalTime_label;
    // Return button
    QPushButton *return_btn;
    // Share button
    QPushButton *share_btn;
    // Total time
    QString totalFormattedTime;
    // Current running time string
    QString currentFormattedTime;

    // Fullscreen detection
    bool fullscreen;

    // Component initialization function
    void Init();

signals:
    // Signal for returning to the main page
    void back(QWidget *close);

public:
    // Initialization function
    PlayerWidget(QWidget *parent = nullptr);

    // Destructor
    ~PlayerWidget();

protected slots:
    // Handle signal when volume is clicked
    void voiceclick(int voice);
    // Handle signal when volume changes
    void voicechange(int voice);

    // Handle play signal
    void playclick();
    // Handle pause signal
    void stopclick();
    // Handle forward signal
    void aheadclick();
    // Handle backward signal
    void backclick();
    // Handle fullscreen signal
    void fullscreenClick();
    // Handle return to main page signal
    void returnclick();
    // Handle total duration
    void getduration(qint64 duration);
    // Handle running time
    void VideoPosChange(qint64 position);
    // Handle progress bar signal
    void ProgressChange(int pos);
    // Handle playback speed signal
    void SpeedChange(int value);
    // Set resources
    void SetResource(QString resource, QPalette currentPal, QSize currentPageSize, int x, int y);
};
#endif // PLAYER_H
