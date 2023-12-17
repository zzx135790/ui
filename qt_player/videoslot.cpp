#include "widget.h"
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDialog>

void Widget::voiceclick(int voice)
{
    static int i = 0;
    i = !i;
    if(i == 1)
    {
        audioOutput->setVolume(0);
    }
    else if(i == 0)
    {
        audioOutput->setVolume(voice);
    }

}

void Widget::voicechange(int voice)
{
//    qDebug()<<voice;
    float value = 0.01 * voice;
    audioOutput->setVolume(value);
}


void Widget::playclick()
{
    multiPlayer->play();
}

void Widget::stopclick()
{
    multiPlayer->pause();
}

void Widget::ProgressChange(int pos)
{
//    qDebug()<<pos;
    if(player_slider->isSliderDown())
    {
        multiPlayer->setPosition(pos * multiPlayer->duration() / 100);
    }
}

void Widget::aheadclick()
{
    qint64 currentpos = multiPlayer->position();
    multiPlayer->setPosition(currentpos + 10000);
}


void Widget::backclick()
{
    qint64 currentpos = multiPlayer->position();
    multiPlayer->setPosition(currentpos - 10000);
}

void Widget::fullscreenClick(){
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


void Widget::getduration(qint64 duration)
{
    QTime totalTime = QTime(0, 0, 0, 0);
    totalTime = totalTime.addMSecs(duration);
    totalFormattedTime = totalTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime);
    totalTime_label->setText(totalFormattedTime);
}

void Widget::VideoPosChange(qint64 position)
{
    if(player_slider->isSliderDown())
    {
        return;
    }
    //    qDebug()<< multiPlayer->source();
    player_slider->setSliderPosition(100 * position / multiPlayer->duration());

    QTime currentTime(0, 0, 0, 0);
    currentTime = currentTime.addMSecs(multiPlayer->position());
    currentFormattedTime = currentTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime);
}

void Widget::SetResource(QString resource)
{
    QUrl url = QUrl::fromLocalFile(resource);
    multiPlayer->setSource(url);
    multiPlayer->play();
    connect(multiPlayer, SIGNAL(positionChanged(qint64)), this, SLOT(VideoPosChange(qint64)));
}

void Widget::SpeedChange(int value)
{
    multiPlayer->setPlaybackRate(value * 2.0 / 8.0);
}
