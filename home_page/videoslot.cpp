#include "video.h"
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDialog>

// Handle the volume button click event
void PlayerWidget::voiceclick(int voice)
{
    static int i = 0;
    i = !i;
    if(i == 1)
    {
        multiPlayer->setVolume(0); // Mute
    }
    else if(i == 0)
    {
        multiPlayer->setVolume(voice); // Set volume
    }
}

// Handle the volume slider value change event
void PlayerWidget::voicechange(int voice)
{
    multiPlayer->setVolume(voice); // Set volume
}

// Handle the return button click event
void PlayerWidget::returnclick(){
    multiPlayer->stop(); // Stop video playback
    delete multiPlayer; // Delete the current QMediaPlayer object
    multiPlayer = new QMediaPlayer; // Create a new QMediaPlayer object
    connect(multiPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64))); // Connect signals and slots
    multiPlayer->setPlaybackRate(1.0);
    multiPlayer->setVideoOutput(videoWidget);
    multiPlayer->setVolume(50); // Set volume
    emit back(this); // Emit the return signal
}

// Handle the play button click event
void PlayerWidget::playclick()
{
    multiPlayer->play(); // Play video
}

// Handle the pause button click event
void PlayerWidget::stopclick()
{
    multiPlayer->pause(); // Pause video playback
}

// Handle the playback slider value change event
void PlayerWidget::ProgressChange(int pos)
{
    if(player_slider->isSliderDown())
    {
        multiPlayer->setPosition(pos * multiPlayer->duration() / 100); // Set video playback position
    }
}

// Handle the forward button click event
void PlayerWidget::aheadclick()
{
    qint64 currentpos = multiPlayer->position();
    multiPlayer->setPosition(currentpos + 10000); // Forward 10 seconds
}

// Handle the back button click event
void PlayerWidget::backclick()
{
    qint64 currentpos = multiPlayer->position();
    multiPlayer->setPosition(currentpos - 10000); // Backward 10 seconds
}

// Handle the fullscreen button click event (unfinished code is commented out)
void PlayerWidget::fullscreenClick(){
    // This part of the code is in an unfinished state and does not implement fullscreen functionality
}

// Handle the video duration change event
void PlayerWidget::getduration(qint64 duration)
{
    QTime totalTime = QTime(0, 0, 0, 0);
    totalTime = totalTime.addMSecs(duration);
    totalFormattedTime = totalTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime);
    totalTime_label->setText(totalFormattedTime);
}

// Handle the video position change event
void PlayerWidget::VideoPosChange(qint64 position)
{
    if(player_slider->isSliderDown())
    {
        return;
    }
    player_slider->setSliderPosition(100 * position / multiPlayer->duration()); // Update playback slider position

    QTime currentTime(0, 0, 0, 0);
    currentTime = currentTime.addMSecs(multiPlayer->position());
    currentFormattedTime = currentTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime);
}

// Set the video resource and play it
void PlayerWidget::SetResource(QString resource, QPalette currentPal, QSize currentPageSize, int x, int y)
{
    QUrl url = QUrl::fromLocalFile(resource); // Get the URL of the local file
    this->resize(currentPageSize);
    this->setPalette(currentPal);
    this->move(x, y);
    multiPlayer->setMedia(url); // Set the video resource
    multiPlayer->play(); // Play the video
    connect(multiPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(VideoPosChange(qint64))); // Connect video position change signal and slot
}

// Handle the speed slider value change event
void PlayerWidget::SpeedChange(int value)
{
    multiPlayer->setPlaybackRate(value * 2.0 / 4.0); // Set video playback speed
}
