#include "video.h"
#include <QVBoxLayout>
#include <QIcon>
#include <QDebug>
#include <QHBoxLayout>
#include <QPalette>
#include <QString>

PlayerWidget::PlayerWidget(QWidget *parent): QWidget(parent), currentFormattedTime("00:00")
{
    this->setWindowTitle("Player"); // Set window title

    QVBoxLayout* vlayout = new QVBoxLayout(this); // Create a vertical layout manager
    QHBoxLayout* hlayout = new QHBoxLayout();
    QHBoxLayout* toplayout = new QHBoxLayout();
    QWidget *spacer = new QWidget(this); // Create a placeholder widget

    multiPlayer = new QMediaPlayer; // Create a multimedia player
    videoWidget = new QVideoWidget(this); // Create a video player widget
    btnWidget= new buttonWidget(this); // Create a custom button widget
    return_btn = new QPushButton(); // Create a return button
    share_btn = new QPushButton(); // Create a share button

    multiPlayer->setPlaybackRate(1.0); // Set playback rate
    multiPlayer->setVideoOutput(videoWidget); // Set video output to the video player widget
    multiPlayer->setVolume(50); // Set volume

    Init(); // Initialize user interface elements

    hlayout->addWidget(playerTime_label,1); // Add the current playtime label to the horizontal layout
    hlayout->addWidget(player_slider,8); // Add the play progress bar to the horizontal layout
    hlayout->addWidget(totalTime_label,1); // Add the total duration label to the horizontal layout

    toplayout->addWidget(return_btn,1); // Add the return button to the top layout
    toplayout->addWidget(spacer,8); // Add the placeholder widget to the top layout
    toplayout->addWidget(share_btn,1); // Add the share button to the top layout

    vlayout->addLayout(toplayout); // Add the top layout to the vertical layout
    vlayout->addWidget(videoWidget, 8); // Add the video player widget to the vertical layout
    vlayout->addLayout(hlayout,1); // Add the horizontal layout to the vertical layout
    vlayout->addWidget(btnWidget, 1); // Add the custom button widget to the vertical layout

    // Connect signals and slots to handle user interactions
    connect(multiPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));
    videoWidget->show(); // Show the video player widget
}

void PlayerWidget::Init()
{
    // Create a playback progress slider and set its style
    player_slider = new QSlider(Qt::Horizontal);
    player_slider->setRange(0, 100);
    player_slider->setValue(0);
    player_slider->setPageStep(0);
    player_slider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "    border: 1px solid #A9A9A9;"
        "    height: 6px;"
        "    margin: 2px 0;"
        "    background: #A9A9A9;"
        "    border-radius: 4px;"
        "}"
        "QSlider::handle:horizontal {"
        "    background: #FFFFFF;"
        "    border: 1px solid #A9A9A9;"
        "    width: 10px;"
        "    margin: -2px 0;"
        "    border-radius: 4px;"
        "}"
        );

    playerTime_label = new QLabel("00:00"); // Create the current playtime label
    playerTime_label->setStyleSheet("color: white;");
    playerTime_label->setAlignment(Qt::AlignCenter);

    totalTime_label = new QLabel("00:00"); // Create the total duration label
    totalTime_label->setStyleSheet("color: white;");
    totalTime_label->setAlignment(Qt::AlignCenter);

    btnWidget->ButtonStyleSet(return_btn,":/button/icon/return.png"); // Set the style of the return button
    btnWidget->ButtonStyleSet(share_btn,":/icon/upload.png"); // Set the style of the share button

    // Connect button click signals to corresponding slots
    connect(return_btn, SIGNAL(clicked()), btnWidget, SLOT(slot_return_click()));
    connect(return_btn, SIGNAL(clicked()), this, SLOT(returnclick()));
    connect(btnWidget, SIGNAL(voice_button_clicked(int)), this, SLOT(voiceclick(int)));
    connect(btnWidget, SIGNAL(play_button_clicked()), this, SLOT(playclick()));
    connect(btnWidget, SIGNAL(pause_button_clicked()), this, SLOT(stopclick()));
    connect(btnWidget, SIGNAL(ahead_button_clicked()), this, SLOT(aheadclick()));
    connect(btnWidget, SIGNAL(back_button_clicked()), this, SLOT(backclick()));
    connect(btnWidget, SIGNAL(fullscreen_button_clicked()), this, SLOT(fullscreenClick()));
    connect(btnWidget, SIGNAL(voice_slider_valueChanged(int)), this, SLOT(voicechange(int)));
    connect(btnWidget, SIGNAL(speed_slider_valueChanged(int)), this, SLOT(SpeedChange(int)));
    connect(player_slider, SIGNAL(valueChanged(int)), this, SLOT(ProgressChange(int)));
}

PlayerWidget::~PlayerWidget()
{
}
