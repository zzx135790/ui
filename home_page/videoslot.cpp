#include "video.h"
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDialog>

void PlayerWidget::voiceclick(int voice)
{
    static int i = 0;
    i = !i;
    if(i == 1)
    {
        multiPlayer->setVolume(0);
    }
    else if(i == 0)
    {
        multiPlayer->setVolume(voice);
    }

}

void PlayerWidget::voicechange(int voice)
{
    //    qDebug()<<voice;
    //    float value = 0.01 * voice;
    multiPlayer->setVolume(voice);
}


void PlayerWidget::playclick()
{
    multiPlayer->play();
}

void PlayerWidget::stopclick()
{
    multiPlayer->pause();
}

void PlayerWidget::ProgressChange(int pos)
{
    //    qDebug()<<pos;
    if(player_slider->isSliderDown())
    {
        multiPlayer->setPosition(pos * multiPlayer->duration() / 100);
    }
}

void PlayerWidget::aheadclick()
{
    qint64 currentpos = multiPlayer->position();
    multiPlayer->setPosition(currentpos + 10000);
}


void PlayerWidget::backclick()
{
    qint64 currentpos = multiPlayer->position();
    multiPlayer->setPosition(currentpos - 10000);
}

void PlayerWidget::fullscreenClick(){
    //    qDebug()<<buttonWidget->pos().x();
    //    qDebug()<<buttonWidget->pos().y();
    //    buttonFrame->raise();
    //    animation->setStartValue(buttonFrame->pos());
    //    animation->setEndValue(QPoint(buttonFrame->pos().x(),buttonFrame->pos().y()- buttonFrame->geometry().height()));
    //    animation->start();

    //    QRect button = buttonWidget->geometry();
    //    QRect video = videoWidget->geometry();
    //    QRegion mask(QRect(video.left(),video.top()+video.height()-button.height(),button.width(),button.height()));
    //    qDebug()<<mask;
    //    buttonWidget->setMask(mask);
    //    static bool ifnFullscreen = 0;
    //    ifnFullscreen ^= 1;
    //    videoWidget->setFullScreen(ifnFullscreen);
}


void PlayerWidget::getduration(qint64 duration)
{
    QTime totalTime = QTime(0, 0, 0, 0);
    totalTime = totalTime.addMSecs(duration);
    totalFormattedTime = totalTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime);
    totalTime_label->setText(totalFormattedTime);
}

void PlayerWidget::VideoPosChange(qint64 position)
{
    if(player_slider->isSliderDown())
    {
        return;
    }
    qDebug()<< position;
    qDebug()<< multiPlayer->duration();
    player_slider->setSliderPosition(100 * position / multiPlayer->duration());

    QTime currentTime(0, 0, 0, 0);
    currentTime = currentTime.addMSecs(multiPlayer->position());
    currentFormattedTime = currentTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime);
}

void PlayerWidget::SetResource(QString resource)
{
    qDebug()<<resource;
    QUrl url = QUrl::fromLocalFile(resource);
    multiPlayer->setMedia(url);
    multiPlayer->play();
    connect(multiPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(VideoPosChange(qint64)));
}

void PlayerWidget::SpeedChange(int value)
{
    multiPlayer->setPlaybackRate(value * 2.0 / 8.0);
}
