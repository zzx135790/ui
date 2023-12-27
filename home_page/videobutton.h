#ifndef BUTTONWIDGET_H
#define BUTTONWIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QSlider>
#include <QHBoxLayout>
#include <QLabel>

class buttonWidget : public QWidget
{
    Q_OBJECT

    QSlider* voice_slider; // Volume slider
    QPushButton* play_button; // Play button
    QPushButton* pause_button; // Pause button
    QPushButton* back_button; // Backward button
    QPushButton* ahead_button; // Forward button
    QPushButton* selectFile_button; // Select file button
    QPushButton* fullscreen_button; // Fullscreen button
    QPushButton* speed_button; // Playback speed button
    QPushButton* voice_button; // Volume control button
    QPushButton* speed_text_button; // Playback speed text button

    QVBoxLayout* mlayout; // Vertical layout
    QHBoxLayout* hlayout1; // Horizontal layout 1
    QString resource; // Resource path

    void Init(); // Initialization function

    int voice_data; // Volume data
    int speed_data; // Playback speed data
    bool playStatus; // Playback status
    bool mute; // Mute status

public:
    buttonWidget(QWidget *parent = nullptr); // Constructor
    void ButtonStyleSet(QPushButton* button, QString IconPath); // Set button style
    ~buttonWidget(); // Destructor

signals:
    void play_button_clicked(); // Play button clicked signal
    void pause_button_clicked(); // Pause button clicked signal
    void ahead_button_clicked(); // Forward button clicked signal
    void back_button_clicked(); // Backward button clicked signal
    void fullscreen_button_clicked(); // Fullscreen button clicked signal
    void voice_button_clicked(int voice); // Volume control button clicked signal
    void voice_slider_valueChanged(int voice); // Volume slider value changed signal
    void speed_slider_valueChanged(int speed); // Playback speed slider value changed signal
    void File_button_clicked(QString resource); // File selection button clicked signal

protected slots:
    void slot_voice_button_clicked(); // Volume control button clicked slot
    void slot_play_button_clicked(); // Play button clicked slot
    void slot_pause_button_clicked(); // Pause button clicked slot
    void slot_ahead_button_clicked(); // Forward button clicked slot
    void slot_back_button_clicked(); // Backward button clicked slot
    void slot_File_button_clicked(); // File selection button clicked slot
    void slot_fullscreen_button_clicked(); // Fullscreen button clicked slot
    void slot_voice_slider_valueChanged(int value); // Volume slider value changed slot
    void slot_speed_valueChanged(); // Playback speed value changed slot
    void slot_return_click(); // Return button clicked slot
};

#endif // BUTTONWIDGET_H
