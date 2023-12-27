#include "videobutton.h"
#include <QFileDialog>
#include <QDebug>

// Handle the click event of the volume button
void buttonWidget::slot_voice_button_clicked(){
    mute = !mute; // Toggle mute state
    if(mute == 1)
    {
        ButtonStyleSet(voice_button, ":/button/icon/novoice.png"); // Set to mute icon
    }
    else
    {
        int voice = voice_data;
        if(voice == 0)
        {
            ButtonStyleSet(voice_button, ":/button/icon/novoice.png"); // Mute state
        }
        else if (voice <= 33)
        {
            ButtonStyleSet(voice_button, ":/button/icon/low_voice.png"); // Low volume state
        }
        else if (voice <= 66)
        {
            ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png"); // Medium volume state
        }
        else
        {
            ButtonStyleSet(voice_button, ":/button/icon/high_voice.png"); // High volume state
        }
    }
    emit voice_button_clicked(voice_data); // Emit volume button click signal and pass volume data
}

// Handle the click event of the play button
void buttonWidget::slot_play_button_clicked(){
    if (playStatus){
        ButtonStyleSet(play_button,":/button/icon/pause.png"); // Switch to pause icon
        emit play_button_clicked(); // Emit play button click signal
    }
    else{
        ButtonStyleSet(play_button,":/button/icon/play.png"); // Switch to play icon
        emit pause_button_clicked(); // Emit pause button click signal
    }
    playStatus ^= 1; // Toggle play status
}

// Handle the click event of the pause button
void buttonWidget::slot_pause_button_clicked(){
    emit pause_button_clicked(); // Emit pause button click signal
}

// Handle the click event of the forward button
void buttonWidget::slot_ahead_button_clicked(){
    emit ahead_button_clicked(); // Emit forward button click signal
}

// Handle the click event of the back button
void buttonWidget::slot_back_button_clicked(){
    emit back_button_clicked(); // Emit back button click signal
}

// Handle the click event of the select file button
void buttonWidget::slot_File_button_clicked(){
    QString resource = QFileDialog::getOpenFileName(this, tr("Select Video Source"), "", tr(" Video Files(*.*)")); // Open file dialog to select video file
    emit File_button_clicked(resource); // Emit select file button click signal and pass the selected file path
}

// Handle the click event of the fullscreen button
void buttonWidget::slot_fullscreen_button_clicked(){
    emit fullscreen_button_clicked(); // Emit fullscreen button click signal
}

// Handle the volume slider value change event
void buttonWidget::slot_voice_slider_valueChanged(int value){
    voice_data = value; // Update volume data
    int voice = value;
    if(voice == 0)
    {
        ButtonStyleSet(voice_button, ":/button/icon/novoice.png"); // Mute state
    }
    else if (voice <= 33)
    {
        ButtonStyleSet(voice_button, ":/button/icon/low_voice.png"); // Low volume state
    }
    else if (voice <= 66)
    {
        ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png"); // Medium volume state
    }
    else
    {
        ButtonStyleSet(voice_button, ":/button/icon/high_voice.png"); // High volume state
    }

    emit voice_slider_valueChanged(value); // Emit volume slider value change signal and pass the new volume value
}

// Handle the click event of the speed button
void buttonWidget::slot_speed_valueChanged(){
    speed_data = (speed_data + 1) % 5; // Toggle speed mode (cycle through 5 modes)
    if (speed_data == 0) speed_data = 1; // Avoid speed being 0
    speed_button->setText(QString::number(speed_data * 2.0 / 4.0, 'f', 1) + QString(" x")); // Update button text display
    emit speed_slider_valueChanged(speed_data); // Emit speed slider value change signal and pass the new speed value
}

// Handle the click event of the return button
void buttonWidget::slot_return_click(){
    playStatus = 0; // Set play status to 0
    ButtonStyleSet(play_button,":/button/icon/pause.png"); // Set the button to the pause icon
}
