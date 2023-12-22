#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "share.h"
#include <QTime>
#include <QVector>
#include <vector>
#include <QFile>
#include <QXmlStreamReader>
#include <QSignalMapper>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class share;

class video_item{
private:
    QString URL;
    QString image;
    QString time;

public:
    video_item(QString url, QString image, QString time);
    ~video_item();
    QString get_URL() ;
    QString get_img() ;
    QString get_Time() ;
    void set_img( QString image) ;
    void set_URL( QString url) ;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    share *widget2 = NULL;
    void writeXmlToFile();

signals:
    QString video_url(const QString &url, const QSize &size, const QPalette &currentPal);

private slots:
    void on_share_3_clicked();
    void comeBackToPrev();
    void post_url(QString url);
    void handleClick();

private:
    Ui::Widget *ui;
    QVector<video_item> *video_list;
    QVector<video_item> *show_list;
    QSignalMapper *signalMapper;
};
#endif // WIDGET_H
