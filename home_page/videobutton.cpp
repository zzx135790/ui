#include "videobutton.h"

void buttonWidget::ButtonStyleSet(QPushButton* button, QString IconPath)
{
    button->setIcon(QIcon(IconPath));
    button->setFlat(true);
    button->setStyleSheet("QPushButton {"
                          "border-radius: 8px;" // 普通状态下的边框圆角
                          "background-color: #232323;"
                          "color: #ffffff;"
                          "padding-top: 5px;" // 上方间距为 15px
                          "padding-bottom: 5px;" // 下方间距为 15px
                          "}"
                          "QPushButton:hover {"
                          "border-color: #FAF9F6;" // 悬停状态下修改边框颜色
                          "background-color: #3C3C3C;"
                          "color: #ffffff"
                          "}"
                          "QPushButton:pressed {"
                          "border-width: 3px;" // 按下状态下增加边框宽度
                          "background-color: #191919;"
                          "color: #ffffff"
                          "}");
}

buttonWidget::buttonWidget(QWidget *parent): QWidget(parent), speed_data(2),
    playStatus(0), mute(0)
{
    mlayout = new QVBoxLayout(this);
    hlayout1 = new QHBoxLayout();
//    hlayout2 = new QHBoxLayout();
//    hlayout3 = new QHBoxLayout();

    Init();

    mlayout->addLayout(hlayout1, 0);
//    mlayout->addLayout(hlayout2, 0);
//    mlayout->addLayout(hlayout3, 0);

}

void buttonWidget::Init()
{


    voice_button = new QPushButton();
    ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png");

    voice_slider = new QSlider(Qt::Horizontal);
    voice_slider->setRange(0, 100);
    voice_slider->setValue(50);
    voice_slider->setPageStep(10);
    voice_slider->setStyleSheet(
        "QSlider::groove:horizontal {"
        "    border: 1px solid #A9A9A9;"
        "    height: 4px;"
        "    margin: 2px 0;"
        "    background: #A9A9A9;"
        "    border-radius: 3px;"
        "}"
        "QSlider::handle:horizontal {"
        "    background: #FFFFFF;"
        "    border: 1px solid #A9A9A9;"
        "    width: 10px;"
        "    margin: -2px 0;"
        "    border-radius: 3px;"
        "}"
//        "QSlider::sub-page:horizontal {"
//        "    background: #3498db;" /* 设置填充部分颜色为深蓝色 */
//        "    border-radius: 3px;" /* 可选：如果你想要填充部分也有圆角 */
//        "    height: 4px;"
//        "}"
        );

    speed_button = new QPushButton();
    speed_button->setText(QString("%1").arg(1.0, 0, 'f', 1) + QString(" x"));

    speed_button->setStyleSheet("QPushButton {"
                                "border-radius: 8px;" // 普通状态下的边框圆角
                                "background-color: #232323;"
                                "color: #ffffff;"
                                "padding-top: 5px;" // 上方间距为 15px
                                "padding-bottom: 5px;" // 下方间距为 15px
                                "}"
                                "QPushButton:hover {"
                                "border-color: #FAF9F6;" // 悬停状态下修改边框颜色
                                "background-color: #3C3C3C;"
                                "color: #ffffff"
                                "}"
                                "QPushButton:pressed {"
                                "border-width: 3px;" // 按下状态下增加边框宽度
                                "background-color: #191919;"
                                "color: #ffffff"
                                "}");

    // speed_button 样式

//    speed_label = new QLabel();
//    speed_label->setText(QString("%1").arg(1.0, 0, 'f', 2) + QString("倍速"));
//    speed_slider = new QSlider(Qt::Horizontal);
//    speed_slider->setRange(0, 8);
//    speed_slider->setTickInterval(2);
//    speed_slider->setTickPosition(QSlider::TicksBelow);
//    speed_slider->setValue(4);
//    speed_slider->setPageStep(2);

    play_button = new QPushButton();
    ButtonStyleSet(play_button, ":/button/icon/pause.png");
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


    hlayout1->addWidget(voice_button,1);
    hlayout1->addWidget(voice_slider,2);
    hlayout1->addWidget(back_button,1);
    hlayout1->addWidget(play_button,1);
    hlayout1->addWidget(ahead_button,1);
    hlayout1->addWidget(speed_button,2);
//    hlayout1->addWidget(selectFile_button,1);
    hlayout1->addWidget(fullscreen_button,1);


//    hlayout3->addWidget(speed_slider);
//    hlayout3->addWidget(speed_label);

    connect(voice_button, SIGNAL(clicked()), this, SLOT(slot_voice_button_clicked()));
    connect(play_button, SIGNAL(clicked()), this, SLOT(slot_paly_button_clicked()));
    connect(pause_button, SIGNAL(clicked()), this, SLOT(slot_pause_button_clicked()));
    connect(ahead_button, SIGNAL(clicked()), this, SLOT(slot_ahead_button_clicked()));
    connect(back_button, SIGNAL(clicked()), this, SLOT(slot_back_button_clicked()));
    connect(selectFile_button, SIGNAL(clicked()), this, SLOT(slot_File_button_clicked()));
    connect(fullscreen_button, SIGNAL(clicked()), this, SLOT(slot_fullscreen_button_clicked()));
    connect(voice_slider, SIGNAL(valueChanged(int)), this, SLOT(slot_voice_slider_valueChanged(int)));
    connect(speed_button, SIGNAL(clicked()), this, SLOT(slot_speed_valueChanged()));
}

buttonWidget::~buttonWidget(){

}

