#include "video.h"
#include <QVBoxLayout>
#include <QIcon>
#include <QDebug>
#include <QHBoxLayout>
#include <QPalette>
#include <QString>


PlayerWidget::PlayerWidget(QWidget *parent): QWidget(parent), currentFormattedTime("00:00")
{
    audioOutput = new QAudioOutput();

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    QHBoxLayout* hlayout = new QHBoxLayout();

    multiPlayer = new QMediaPlayer;
    videoWidget = new QVideoWidget(this);
    btnWidget= new buttonWidget(this);

    multiPlayer->setPlaybackRate(1.0);
    multiPlayer->setVideoOutput(videoWidget);
    multiPlayer->setVolume(50);

    Init();

    hlayout->addWidget(playerTime_label,1);
    hlayout->addWidget(player_slider,8);
    hlayout->addWidget(totalTime_label,1);

    vlayout->addWidget(videoWidget, 8);
    vlayout->addLayout(hlayout,1);
    vlayout->addWidget(btnWidget, 1);

    animation = new QPropertyAnimation(btnWidget, "pos");
    animation->setDuration(1000);


    // 在动画结束后更新布局的位置
    //    connect(animation, &QPropertyAnimation::finished, this, [=]() {
    //        vlayout->setGeometry(QRect(vlayout->geometry().x(), vlayout->geometry().y() - 100, vlayout->geometry().width(), vlayout->geometry().height()));
    //    });

    connect(multiPlayer, SIGNAL(durationChanged(qint64)), this, SLOT(getduration(qint64)));

    videoWidget->show();
    resize(500, 800);

//    qDebug()<<multiPlayer->position();
}

void PlayerWidget::Init()
{

    player_slider = new QSlider(Qt::Horizontal);
    player_slider->setRange(0, 100);
    player_slider->setValue(0);
    player_slider->setPageStep(0);

    playerTime_label = new QLabel("00:00");
    totalTime_label = new QLabel("00:00");

    connect(btnWidget, SIGNAL(voice_button_clicked(int)),this,SLOT(voiceclick(int)));
    connect(btnWidget, SIGNAL(play_button_clicked()),this,SLOT(playclick()));
    connect(btnWidget, SIGNAL(pause_button_clicked()),this,SLOT(stopclick()));
    connect(btnWidget, SIGNAL(ahead_button_clicked()),this,SLOT(aheadclick()));
    connect(btnWidget, SIGNAL(back_button_clicked()),this,SLOT(backclick()));
    connect(btnWidget, SIGNAL(fullscreen_button_clicked()),this,SLOT(fullscreenClick()));
    connect(btnWidget, SIGNAL(voice_slider_valueChanged(int)),this,SLOT(voicechange(int)));
    connect(btnWidget, SIGNAL(speed_slider_valueChanged(int)),this,SLOT(SpeedChange(int)));
//    connect(btnWidget, SIGNAL(File_button_clicked(QString)),this,SLOT(SetResource(QString,QPalette,QSize)));
    connect(player_slider, SIGNAL(valueChanged(int)), this, SLOT(ProgressChange(int)));
}

PlayerWidget::~PlayerWidget()
{
}
