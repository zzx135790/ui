#include "videobutton.h"
#include <QFileDialog>
#include <QDebug>
void buttonWidget::slot_voice_button_clicked(){
    mute = !mute;
    if(mute == 1)
    {
        ButtonStyleSet(voice_button, ":/button/icon/novoice.png");
    }
    else
    {
        int voice = voice_data;
        if(voice == 0)
        {
            ButtonStyleSet(voice_button, ":/button/icon/novoice.png");
        }
        else if (voice<=33)
        {
            ButtonStyleSet(voice_button, ":/button/icon/low_voice.png");
        }
        else if (voice<=66)
        {
            ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png");
        }
        else
        {
            ButtonStyleSet(voice_button, ":/button/icon/high_voice.png");
        }
    }
    emit voice_button_clicked(voice_data);
}

void buttonWidget::slot_paly_button_clicked(){
    if (playStatus){
        ButtonStyleSet(play_button,":/button/icon/pause.png");
//        qDebug() << "play signal";
        emit play_button_clicked();
    }
    else{
        ButtonStyleSet(play_button,":/button/icon/play.png");
        emit pause_button_clicked();
    }
    playStatus ^= 1;

}

void buttonWidget::slot_pause_button_clicked(){
    emit pause_button_clicked();
}

void buttonWidget::slot_ahead_button_clicked(){
    emit ahead_button_clicked();
}

void buttonWidget::slot_back_button_clicked(){
    emit back_button_clicked();
}

void buttonWidget::slot_File_button_clicked(){
    QString resource = QFileDialog::getOpenFileName(this, tr("选择播放源"), "", tr(" Video Files(*.*)"));
    emit File_button_clicked(resource);
}

void buttonWidget::slot_fullscreen_button_clicked(){
    emit fullscreen_button_clicked();
}

void buttonWidget::slot_voice_slider_valueChanged(int value){
    voice_data = value;
    int voice = value;
    if(voice == 0)
    {
        ButtonStyleSet(voice_button, ":/button/icon/novoice.png");
    }
    else if (voice<=33)
    {
        ButtonStyleSet(voice_button, ":/button/icon/low_voice.png");
    }
    else if (voice<=66)
    {
        ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png");
    }
    else
    {
        ButtonStyleSet(voice_button, ":/button/icon/high_voice.png");
    }

    emit voice_slider_valueChanged(value);
}


void buttonWidget::slot_speed_valueChanged(){
    speed_data = ( speed_data+1 ) % 5;
    if (speed_data == 0) speed_data = 1;
    speed_button->setText(QString::number(speed_data * 2.0 / 4.0, 'f', 1) + QString(" x"));
    emit speed_slider_valueChanged(speed_data);
}

void buttonWidget::slot_return_click(){
    playStatus = 1;
    ButtonStyleSet(play_button,":/button/icon/pause.png");
}


