#include "buttonwidget.h"

void buttonWidget::ButtonStyleSet(QPushButton* button, QString IconPath)
{
    button->setIcon(QIcon(IconPath));
    button->setFlat(true);
    button->setStyleSheet("QPushButton:hover {background-color: grey;} QPushButton:pressed {background-color: darkGrey;}");
}

buttonWidget::buttonWidget(QWidget *parent): QWidget(parent)
{
    mlayout = new QVBoxLayout(this);
    hlayout1 = new QHBoxLayout();
    hlayout2 = new QHBoxLayout();
    hlayout3 = new QHBoxLayout();

    Init();

    mlayout->addLayout(hlayout1, 0);
    mlayout->addLayout(hlayout2, 0);
    mlayout->addLayout(hlayout3, 0);

}

void buttonWidget::Init()
{


    voice_button = new QPushButton();
    ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png");

    voice_slider = new QSlider(Qt::Horizontal);
    voice_slider->setRange(0, 100);
    voice_slider->setValue(50);
    voice_slider->setPageStep(10);
    mute = 0;
    voice_data = 50;
    speed_button = new QPushButton();
    ButtonStyleSet(speed_button, ":/button/icon/speed.png");

    speed_label = new QLabel();
    speed_label->setText(QString("%1").arg(1.0, 0, 'f', 2) + QString("倍速"));
    speed_slider = new QSlider(Qt::Horizontal);
    speed_slider->setRange(0, 8);
    speed_slider->setTickInterval(2);
    speed_slider->setTickPosition(QSlider::TicksBelow);
    speed_slider->setValue(4);
    speed_slider->setPageStep(2);


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


    hlayout1->addWidget(paly_button);
    hlayout1->addWidget(pause_button);
    hlayout1->addWidget(back_button);
    hlayout1->addWidget(ahead_button);
    hlayout1->addWidget(selectFile_button);
    hlayout1->addWidget(fullscreen_button);
    hlayout2->addWidget(voice_button);
    hlayout2->addWidget(voice_slider);
    hlayout3->addWidget(speed_button);
    hlayout3->addWidget(speed_slider);
    hlayout3->addWidget(speed_label);

    connect(voice_button, SIGNAL(clicked()), this, SLOT(slot_voice_button_clicked()));
    connect(paly_button, SIGNAL(clicked()), this, SLOT(slot_paly_button_clicked()));
    connect(pause_button, SIGNAL(clicked()), this, SLOT(slot_pause_button_clicked()));
    connect(ahead_button, SIGNAL(clicked()), this, SLOT(slot_ahead_button_clicked()));
    connect(back_button, SIGNAL(clicked()), this, SLOT(slot_back_button_clicked()));
    connect(selectFile_button, SIGNAL(clicked()), this, SLOT(slot_File_button_clicked()));
    connect(fullscreen_button, SIGNAL(clicked()), this, SLOT(slot_fullscreen_button_clicked()));
    connect(voice_slider, SIGNAL(valueChanged(int)), this, SLOT(slot_voice_slider_valueChanged(int)));
    connect(speed_slider, SIGNAL(valueChanged(int)), this, SLOT(slot_speed_slider_valueChanged(int)));
}

buttonWidget::~buttonWidget(){

}

