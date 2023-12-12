#include "widget.h"
#include <QVBoxLayout>
#include <QIcon>
#include <QDebug>
#include <QHBoxLayout>
#include <QPalette>

void Widget::ButtonStyleSet(QPushButton* button, QString IconPath)
{
    button->setIcon(QIcon(IconPath));
    button->setFlat(true);
    button->setStyleSheet("QPushButton:hover {background-color: grey;} QPushButton:pressed {background-color: darkGrey;}");
}


Widget::Widget(QWidget *parent): QWidget(parent), voice_data(50),
    currentFormattedTime("00:00")
{
    audioOutput = new QAudioOutput();

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    hlayout1 = new QHBoxLayout();
    hlayout2 = new QHBoxLayout();
    hlayout3 = new QHBoxLayout();

    multiPlayer = new QMediaPlayer;
    videoWidget = new QVideoWidget(this);

    multiPlayer->setPlaybackRate(1.0);
    multiPlayer->setVideoOutput(videoWidget);
    multiPlayer->setAudioOutput(audioOutput);
    audioOutput->setVolume(voice_data);

    Init();

    vlayout->addWidget(videoWidget, 8);
    vlayout->addWidget(player_slider, 1);
    vlayout->addLayout(hlayout1, 0);
    vlayout->addLayout(hlayout2, 0);
    vlayout->addLayout(hlayout3, 0);

    connect(multiPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));
//    connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(VideoPosChange(qint64)));

    videoWidget->show();

    resize(300, 500);
}

void Widget::Init()
{
    voice_button = new QPushButton();
    ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png");

    voice_slider = new QSlider(Qt::Horizontal);
    voice_slider->setRange(0, 100);
    voice_slider->setValue(50);

    speed_button = new QPushButton();
    ButtonStyleSet(speed_button, ":/button/icon/speed.png");

    speed_label = new QLabel();
    speed_slider = new QSlider(Qt::Horizontal);
    speed_slider->setRange(0, 8);
    speed_slider->setTickInterval(1);
    speed_slider->setValue(4);
    speed_label->setText(QString("%1").arg(1.0, 0, 'f', 2) + QString("倍速"));

    paly_button = new QPushButton();
    ButtonStyleSet(paly_button, ":/button/icon/play.png");
    pause_button = new QPushButton();
    ButtonStyleSet(pause_button, ":/button/icon/pause.png");
    back_button = new QPushButton();
    ButtonStyleSet(back_button, ":/button/icon/back.png");
    ahead_button = new QPushButton();
    ButtonStyleSet(ahead_button, ":/button/icon/ahead.png");
    fullscreen_button = new QPushButton();
    ButtonStyleSet(fullscreen_button, ":/button/icon/fullScreen.png");
    selectFile_button = new QPushButton();
    ButtonStyleSet(selectFile_button, ":/button/icon/select.png");

    player_slider = new QSlider(Qt::Horizontal);
    player_slider->setRange(0, 100);
    player_slider->setValue(0);

    playerTime_label = new QLabel();
    hlayout1->addWidget(paly_button);
    hlayout1->addWidget(pause_button);
    hlayout1->addWidget(back_button);
    hlayout1->addWidget(ahead_button);
    hlayout1->addWidget(selectFile_button);
    hlayout1->addWidget(fullscreen_button);
    hlayout1->addWidget(playerTime_label);

    hlayout2->addWidget(voice_button);
    hlayout2->addWidget(voice_slider);
//    hlayout1->addStretch();
    hlayout3->addWidget(speed_button);
    hlayout3->addWidget(speed_slider);
    hlayout3->addWidget(speed_label);
//    hlayout1->addStretch();
    connect(voice_button, SIGNAL(clicked()), this, SLOT(voiceclick()));
    connect(voice_slider, SIGNAL(valueChanged(int)), this, SLOT(voicechange(int)));
    connect(paly_button, SIGNAL(clicked()), this, SLOT(playclick()));
    connect(pause_button, SIGNAL(clicked()), this, SLOT(stopclick()));
    connect(player_slider, SIGNAL(valueChanged(int)), this, SLOT(ProgressChange(int)));
    connect(ahead_button, SIGNAL(clicked()), this, SLOT(aheadclick()));
    connect(back_button, SIGNAL(clicked()), this, SLOT(backclick()));
    connect(selectFile_button, SIGNAL(clicked()), this, SLOT(SetResource()));
    connect(speed_slider, SIGNAL(valueChanged(int)), this, SLOT(SpeedChange(int)));
    connect(fullscreen_button, SIGNAL(clicked()), this, SLOT(fullscreenClick()));
}

Widget::~Widget()
{
}
