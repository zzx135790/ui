#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QPainter>
#include <QPushButton>
#include "widget.h"

namespace Ui {
class Video;
}

class Widget;

class Video : public QWidget
{
    Q_OBJECT

public:
    explicit Video(QWidget *parent = nullptr);
    void onNumberButtonClicked();
    ~Video();
    Widget *widget;

signals:
    void back();
//    void receiveURL(const QString &url, const QSize &size, const QPalette &currentPal);

private slots:
    void return_to_home();

private:
    Ui::Video *ui;
    QMediaPlayer *player;
    QVideoWidget *videoWidget;
};

#endif // VIDEO_H
