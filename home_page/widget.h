#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "share.h"
#include "video.h"
#include <QTime>
#include <QVector>
#include <vector>
#include <QFile>
#include <QXmlStreamReader>
#include <QSignalMapper>
#include <QDebug>
#include <QCoreApplication>
#include <QMediaPlayer>
#include <QVideoProbe>
#include <QVideoFrame>
#include <QImage>
#include <QEventLoop>
#include <QAbstractVideoSurface>
#include <QVideoSurfaceFormat>
#include <QPainter>
#include <QPixmap>
#include <QTemporaryFile>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class MyVideoSurface : public QAbstractVideoSurface {
    Q_OBJECT
public:
    MyVideoSurface(QObject *parent = nullptr);
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const override;
    bool present(const QVideoFrame &frame) override;

signals:
    void frameAvailable(QImage frame);
};


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
    void video_url(const QString url,const QPalette currentPal,const QSize currentPageSize, const int x, const int y);
    void list_change();

private slots:
    void on_share_3_clicked();
    void comeBackToPrev(QWidget *close);
    void post_url(QString url,QSize currentPageSize);
    void addVideo();
    void saveCover(const QImage &frame);
    void handleClick();
    void changeList();


private:
    Ui::Widget *ui;
    PlayerWidget *videoWidget;
    MyVideoSurface *surface;
    QMediaPlayer *videoTest;
    QVector<video_item> *video_list;
    QVector<video_item> *show_list;
    QSignalMapper *signalMapper;

    QString cover_path;
    QString data_path;
    QString video_path;
    QString date;
    QEventLoop loop;
};
#endif // WIDGET_H
