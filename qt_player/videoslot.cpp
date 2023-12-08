#include "widget.h"
#include <QDebug>
#include <QIcon>
#include <QFile>
#include <QFileDialog>

void Widget::voiceclick()
{
    static int i = 0;
    i = !i;
    if(i == 1)
    {
        audioOutput->setVolume(0);
        ButtonStyleSet(voice_button, ":/button/icon/novoice.png");
    }
    else if(i == 0)
    {
        audioOutput->setVolume(voice_data);
        ButtonStyleSet(voice_button, ":/button/icon/voice.png");
    }

}

void Widget::voicechange(int voice)
{
    audioOutput->setVolume(voice);
    if(voice == 0)
    {
        ButtonStyleSet(voice_button, ":/button/icon/novoice.png");
    }
    else
    {
        ButtonStyleSet(voice_button, ":/button/icon/voice.png");
    }
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
    if(player_slider->isSliderDown())
    {
        multiPlayer->setPosition(pos * multiPlayer->duration() / 100);
    }
}


void Widget::getduration(qint64 duration)
{
    QTime totalTime = QTime(0, 0, 0, 0);
    totalTime = totalTime.addMSecs(duration);
    totalFormattedTime = totalTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime + " / " + totalFormattedTime);
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
    static bool ifnFullscreen = 0;
    ifnFullscreen ^= 1;
    videoWidget->setFullScreen(ifnFullscreen);
}


void Widget::VideoPosChange(qint64 position)
{
    if(player_slider->isSliderDown())
    {
        return;
    }
    qDebug()<< multiPlayer->source();
    player_slider->setSliderPosition(100 * position / multiPlayer->duration());

    QTime currentTime(0, 0, 0, 0);
    currentTime = currentTime.addMSecs(multiPlayer->position());
    currentFormattedTime = currentTime.toString("mm:ss");
    playerTime_label->setText(currentFormattedTime + " / " + totalFormattedTime);
}

void Widget::SetResource()
{
    resource = QFileDialog::getOpenFileName(this, tr("选择播放源"), "", tr(" Video Files(*.mp4)"));
    QUrl url = QUrl::fromLocalFile(resource);
    multiPlayer->setSource(url);
    multiPlayer->play();
}

void Widget::SpeedChange(int value)
{
    speed_label->setText(QString::number(value * 2.0 / 8.0, 'g', 3) + QString("倍速"));
    multiPlayer->setPlaybackRate(value * 2.0 / 8.0);
}
