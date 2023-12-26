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

//    QLabel* speed_label;
//    QSlider* speed_slider;
    QSlider* voice_slider;

    QPushButton* play_button;
    QPushButton* pause_button;
    QPushButton* back_button;
    QPushButton* ahead_button;
    QPushButton* selectFile_button;
    QPushButton* fullscreen_button;
    QPushButton* speed_button;
    QPushButton* voice_button;
    QPushButton* speed_text_button;

    QVBoxLayout* mlayout;
    QHBoxLayout* hlayout1;
//    QHBoxLayout* hlayout2;
//    QHBoxLayout* hlayout3;

    QString resource;


    void Init();

    int voice_data;
    int speed_data;
    bool playStatus;
    bool mute;

public:

    buttonWidget(QWidget *parent = nullptr);
    void ButtonStyleSet(QPushButton* button, QString IconPath);
    ~buttonWidget();

signals:

    void play_button_clicked();
    void pause_button_clicked();
    void ahead_button_clicked();
    void back_button_clicked();
    void fullscreen_button_clicked();
    void voice_button_clicked(int voice);
    void voice_slider_valueChanged(int voice);
    void speed_slider_valueChanged(int speed);
    void File_button_clicked(QString resource);

protected slots:
    void slot_voice_button_clicked();
    void slot_paly_button_clicked();
    void slot_pause_button_clicked();
    void slot_ahead_button_clicked();
    void slot_back_button_clicked();
    void slot_File_button_clicked();
    void slot_fullscreen_button_clicked();
    void slot_voice_slider_valueChanged(int value);
    void slot_speed_valueChanged();
    void slot_return_click();
};

#endif // BUTTONWIDGET_H
