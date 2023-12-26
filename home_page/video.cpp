#include "video.h"
#include <QVBoxLayout>
#include <QIcon>
#include <QDebug>
#include <QHBoxLayout>
#include <QPalette>
#include <QString>


PlayerWidget::PlayerWidget(QWidget *parent): QWidget(parent), currentFormattedTime("00:00")
{
    this->setWindowTitle("Player");
    audioOutput = new QAudioOutput();

    QVBoxLayout* vlayout = new QVBoxLayout(this);
    QHBoxLayout* hlayout = new QHBoxLayout();
    QHBoxLayout* toplayout = new QHBoxLayout();
    QWidget *spacer = new QWidget(this);

    multiPlayer = new QMediaPlayer;
    videoWidget = new QVideoWidget(this);
    btnWidget= new buttonWidget(this);
    return_btn = new QPushButton();

    multiPlayer->setPlaybackRate(1.0);
    multiPlayer->setVideoOutput(videoWidget);
    multiPlayer->setVolume(50);

    Init();

    hlayout->addWidget(playerTime_label,1);
    hlayout->addWidget(player_slider,8);
    hlayout->addWidget(totalTime_label,1);

    toplayout->addWidget(return_btn,1);
    toplayout->addWidget(spacer,9);

    vlayout->addLayout(toplayout);
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
//    resize(500, 800);

//    qDebug()<<multiPlayer->position();
}

void PlayerWidget::Init()
{

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
//        "QSlider::sub-page:horizontal {"
//        "    background: #3498db;" /* 设置填充部分颜色为深蓝色 */
//        "    border-radius: 4px;" /* 可选：如果你想要填充部分也有圆角 */
//        "    height: 6px;"
//        "}"
        );

    playerTime_label = new QLabel("00:00");
    playerTime_label->setStyleSheet("color: white;");
    totalTime_label = new QLabel("00:00");
    totalTime_label->setStyleSheet("color: white;");
    btnWidget->ButtonStyleSet(return_btn,":/button/icon/return.png");
    connect(return_btn, SIGNAL(clicked()),btnWidget,SLOT(slot_return_click()));
    connect(return_btn, SIGNAL(clicked()),this,SLOT(returnclick()));
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
