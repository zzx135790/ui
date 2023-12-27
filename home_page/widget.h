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

// Custom video surface class
class MyVideoSurface : public QAbstractVideoSurface {
    Q_OBJECT
public:
    MyVideoSurface(QObject *parent = nullptr);

    // Supported pixel formats
    QList<QVideoFrame::PixelFormat> supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const override;

    // Present video frames
    bool present(const QVideoFrame &frame) override;

signals:
    void frameAvailable(QImage frame); // Signal for available video frame
};

class share;

// Video item class
class video_item{
private:
    QString URL; // Resource URL
    QString image; // Cover image URL
    QString time; // Creation date

public:
    video_item(QString url, QString image, QString time); // Constructor
    ~video_item();
    QString get_URL() ; // Get URL
    QString get_img() ; // Get cover image
    QString get_Time() ; // Get time
    void set_img( QString image) ; // Set cover image
    void set_URL( QString url) ; // Set URL
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    share *widget2 = NULL;
    void writeXmlToFile(); // Write XML data to file

signals:
    void video_url(const QString url,const QPalette currentPal,const QSize currentPageSize, const int x, const int y); // Video URL signal
    void list_change(); // List change signal

private slots:
    void on_share_3_clicked(); // "Share" button click slot
    void comeBackToPrev(QWidget *close); // Return to previous page slot
    void post_url(QString url); // Send video URL slot
    void addVideo(); // Add video item slot
    void saveCover(const QImage &frame); // Save video cover slot
    void handleClick(); // Handle click events slot
    void changeList(); // Change video list slot

private:
    Ui::Widget *ui; // Page
    PlayerWidget *videoWidget; // Playback page
    MyVideoSurface *surface; // Get cover image
    QMediaPlayer *videoTest; // Player for getting cover image
    QVector<video_item> *video_list; // List for storing videos
    QVector<video_item> *show_list; // List for displaying videos

    QString cover_path; // Cover image path
    QString data_path; // Data path
    QString video_path; // Video path
    QString date; // Date
    QEventLoop loop; // Event loop
};
#endif // WIDGET_H
