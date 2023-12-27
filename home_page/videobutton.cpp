#include "videobutton.h"

// Set button style, including icon, border, and color
void buttonWidget::ButtonStyleSet(QPushButton* button, QString IconPath)
{
    button->setIcon(QIcon(IconPath)); // Set button icon
    button->setFlat(true); // Set the button to a flat style with no border
    button->setStyleSheet("QPushButton {"
                          "border-radius: 8px;" // Set button border radius
                          "background-color: #232323;" // Set button background color
                          "color: #ffffff;" // Set text color to white
                          "padding-top: 5px;" // Top padding
                          "padding-bottom: 5px;" // Bottom padding
                          "}"
                          "QPushButton:hover {" // Style when mouse hovers over the button
                          "border-color: #FAF9F6;" // Modify border color
                          "background-color: #3C3C3C;" // Modify background color
                          "color: #ffffff" // Modify text color
                          "}"
                          "QPushButton:pressed {" // Style when pressed
                          "border-width: 3px;" // Increase border width
                          "background-color: #191919;" // Modify background color
                          "color: #ffffff" // Modify text color
                          "}");
}

buttonWidget::buttonWidget(QWidget *parent): QWidget(parent), speed_data(2),
    playStatus(0), mute(0)
{
    mlayout = new QVBoxLayout(this); // Create a vertical layout manager
    hlayout1 = new QHBoxLayout();

    Init(); // Initialize user interface elements

    mlayout->addLayout(hlayout1, 0); // Add the horizontal layout to the vertical layout
}

void buttonWidget::Init()
{
    voice_button = new QPushButton(); // Create a sound button
    ButtonStyleSet(voice_button, ":/button/icon/mid_voice.png"); // Set sound button style

    voice_slider = new QSlider(Qt::Horizontal); // Create a sound slider
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
        );

    speed_button = new QPushButton(); // Create a speed button
    speed_button->setText(QString("%1").arg(1.0, 0, 'f', 1) + QString(" x")); // Set the text of the speed button
    speed_button->setStyleSheet("QPushButton {"
                                "border-radius: 8px;"
                                "background-color: #232323;"
                                "color: #ffffff;"
                                "padding-top: 5px;"
                                "padding-bottom: 5px;"
                                "}"
                                "QPushButton:hover {"
                                "border-color: #FAF9F6;"
                                "background-color: #3C3C3C;"
                                "color: #ffffff"
                                "}"
                                "QPushButton:pressed {"
                                "border-width: 3px;"
                                "background-color: #191919;"
                                "color: #ffffff"
                                "}");

    play_button = new QPushButton(); // Create a play button
    ButtonStyleSet(play_button, ":/button/icon/pause.png"); // Set play button style
    pause_button = new QPushButton(); // Create a pause button
    ButtonStyleSet(pause_button, ":/button/icon/pause.png"); // Set pause button style
    back_button = new QPushButton(); // Create a back button
    ButtonStyleSet(back_button, ":/button/icon/back.png"); // Set back button style
    ahead_button = new QPushButton(); // Create a forward button
    ButtonStyleSet(ahead_button, ":/button/icon/ahead.png"); // Set forward button style
    fullscreen_button = new QPushButton(); // Create a fullscreen button
    ButtonStyleSet(fullscreen_button, ":/button/icon/fullScreen.png"); // Set fullscreen button style
    selectFile_button = new QPushButton(); // Create a select file button
    ButtonStyleSet(selectFile_button, ":/button/icon/select.png"); // Set select file button style

    // Add buttons and sliders to the horizontal layout
    hlayout1->addWidget(voice_button,1);
    hlayout1->addWidget(voice_slider,2);
    hlayout1->addWidget(back_button,1);
    hlayout1->addWidget(play_button,1);
    hlayout1->addWidget(ahead_button,1);
    hlayout1->addWidget(speed_button,2);
    hlayout1->addWidget(fullscreen_button,1);

    // Connect button and slider signals to corresponding slots for user interaction
    connect(voice_button, SIGNAL(clicked()), this, SLOT(slot_voice_button_clicked()));
    connect(play_button, SIGNAL(clicked()), this, SLOT(slot_play_button_clicked()));
    connect(pause_button, SIGNAL(clicked()), this, SLOT(slot_pause_button_clicked()));
    connect(ahead_button, SIGNAL(clicked()), this, SLOT(slot_ahead_button_clicked()));
    connect(back_button, SIGNAL(clicked()), this, SLOT(slot_back_button_clicked()));
    connect(selectFile_button, SIGNAL(clicked()), this, SLOT(slot_File_button_clicked()));
    connect(fullscreen_button, SIGNAL(clicked()), this, SLOT(slot_fullscreen_button_clicked()));
    connect(voice_slider, SIGNAL(valueChanged(int)), this, SLOT(slot_voice_slider_valueChanged(int)));
    connect(speed_button, SIGNAL(clicked()), this, SLOT(slot_speed_valueChanged()));
}

buttonWidget::~buttonWidget()
{
}
