#include "widget.h"
#include "video.h"
#include "ui_widget.h"
#include <QDir>

MyVideoSurface::MyVideoSurface(QObject *parent) : QAbstractVideoSurface(parent) {}

QList<QVideoFrame::PixelFormat> MyVideoSurface::supportedPixelFormats(QAbstractVideoBuffer::HandleType handleType) const {
    Q_UNUSED(handleType);
    return QList<QVideoFrame::PixelFormat>() << QVideoFrame::Format_RGB32;
}

bool MyVideoSurface::present(const QVideoFrame &frame) {

    QVideoFrame cloneFrame(frame);
    cloneFrame.map(QAbstractVideoBuffer::ReadOnly);
    QImage image(cloneFrame.bits(), cloneFrame.width(), cloneFrame.height(), QVideoFrame::imageFormatFromPixelFormat(cloneFrame.pixelFormat()));
    cloneFrame.unmap();
    emit frameAvailable(image); // Emit the frameAvailable signal
    return true;
}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,video_list(new QVector<video_item>)
    ,show_list(new QVector<video_item>)
{
    cover_path = "./source/img/";
    data_path = "./source/data.xml";
    video_path = "./source/video/";
    date = QDate::currentDate().toString("yyyy-MM-dd");

    ui->setupUi(this);
    this->widget2 =new share;
    connect(this->widget2,SIGNAL(back(QWidget*)),this,SLOT(comeBackToPrev(QWidget*)));
    connect(this,&Widget::list_change,this,&Widget::changeList);
    connect(this, &Widget::video_url, this, &Widget::handleClick);

    QString button_sheet_one = "QPushButton {"
                       "border: 2px dashed #696666;"
                       "border-radius: 10px;"
                       "background-color: #232323;"
                       "}"
                       "QPushButton:hover {"
                       "border: 2px dashed #696666;" // 悬停状态下修改边框颜色
                       "border-radius: 10px;"
                       "background-color: #3C3C3C;"
                       "}"
                       "QPushButton:pressed {"
                       "background-color: #696666;" // 按下状态下修改背景颜色
                       "border-radius: 10px;"
                       "background-color: #191919;"
                               "}";

    QString button_sheet_two = "QPushButton {"
                               "border: 2px solid #FAF9F6;" // 普通状态下的边框样式
                               "border-radius: 8px;" // 普通状态下的边框圆角
                               "color: #ffffff"
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
                               "}";


    QString button_sheet_five = "QPushButton {"
                               "border: 2px solid #539ec6;" // 普通状态下的边框样式
                               "border-radius: 8px;" // 普通状态下的边框圆角
                               "color: #ffffff"
                               "}"
                               "QPushButton:hover {"
                               "border-color: #0b6a9b;" // 悬停状态下修改边框颜色
                               "background-color: #3C3C3C;"
                               "color: #ffffff"
                               "}"
                               "QPushButton:pressed {"
                               "border-width: 3px;" // 按下状态下增加边框宽度
                               "background-color: #191919;"
                               "color: #ffffff"
                               "}";

    QString button_sheet_three = "QPushButton {"
                                 "border-radius: 8px;" // 普通状态下的边框圆角
                                 "background-color: #232323;"
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
                                 "}";

    QString button_sheet_four = "QPushButton {"
                                 "border:10px solid #FAF9F6;"
                                 "border-radius: 50px;"
                                 "}"
                                 "QPushButton:hover {"
                                 "border:10px solid #FAF9F6;"
                                 "}"
                                 "QPushButton:pressed {"
                                 "border:10px dashed #3C3C3C;"

                                 "}";

    QPushButton *view_29 = findChild<QPushButton*>("video_29");
    QPushButton *view_30 = findChild<QPushButton*>("video_30");
    QPushButton *view_31 = findChild<QPushButton*>("video_31");
    QPushButton *view_32 = findChild<QPushButton*>("video_32");
    QPushButton *view_33 = findChild<QPushButton*>("video_33");
    QPushButton *view_34 = findChild<QPushButton*>("video_34");
    QPushButton *view_35 = findChild<QPushButton*>("video_35");
    QPushButton *view_36 = findChild<QPushButton*>("video_36");
    QPushButton *view_37 = findChild<QPushButton*>("video_37");
    QPushButton *view_38 = findChild<QPushButton*>("video_38");
    QPushButton *view_39 = findChild<QPushButton*>("video_39");
    QPushButton *view_40 = findChild<QPushButton*>("video_40");
    QPushButton *view_41 = findChild<QPushButton*>("video_41");
    QPushButton *view_42 = findChild<QPushButton*>("video_42");
    QPushButton *view_all = findChild<QPushButton*>("view_all");

    QList<QPushButton*> buttons = {
        view_29, view_30, view_31, view_32, view_33,
        view_34, view_35, view_36, view_37, view_38,
        view_39, view_40, view_41, view_42
    };

    view_all->setStyleSheet(button_sheet_two);


    QPushButton *share_3 = findChild<QPushButton*>("share_3");
    QPushButton *user_3 = findChild<QPushButton*>("user_3");
    QPushButton *shoot = findChild<QPushButton*>("shoot");

    connect(shoot,SIGNAL(clicked()),this,SLOT(addVideo()));

    share_3->setStyleSheet(button_sheet_three);
    user_3->setStyleSheet(button_sheet_three);
    shoot->setStyleSheet(button_sheet_four);



    QFile file_org(data_path);
    QDir cover(cover_path);
    QDir vdo(video_path);
    if (!file_org.exists()||!cover.exists()||!vdo.exists()) {
        // 文件不存在，执行你的函数或操作
        writeXmlToFile();
        qDebug() << "File doesn't exist, performing the operation...";
    } else {
        // 文件存在，不执行操作
        qDebug() << "File already exists, skipping the operation...";
    }



    //读取文件内容

    QFile file(data_path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        // Handle file opening error

    }

    QXmlStreamReader xml(&file);

    while (!xml.atEnd() && !xml.hasError()) {
        QXmlStreamReader::TokenType token = xml.readNext();

        if (token == QXmlStreamReader::StartElement && xml.name() == "mediaItem") {
            QString imagePath;
            QString videoPath;
            QString createTime;

            while (!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == "mediaItem")) {
                xml.readNext();

                if (xml.tokenType() == QXmlStreamReader::StartElement) {
                    if (xml.name() == "imagePath") {
                        xml.readNext();
                        imagePath = xml.text().toString();
                    } else if (xml.name() == "videoPath") {
                        xml.readNext();
                        videoPath = xml.text().toString();
                    } else if (xml.name() == "createTime") {
                        xml.readNext();
                        createTime = xml.text().toString();

                    }
                }
            }

            // Create VideoItem object and add it to video_list
            video_item video(videoPath, imagePath, createTime);
            video_list->push_back(video);
        }
    }
    if (xml.hasError()) {
        // Handle XML parsing error
        qDebug() << ("解析xml文件失败\n");
    }

    file.close();


    emit list_change();



    QPushButton *lock_1 = findChild<QPushButton*>("plus");
    QPushButton *lock_2 = findChild<QPushButton*>("lock_1");
    QPushButton *lock_3 = findChild<QPushButton*>("lock_2");

    QList<QPushButton*> buttons_2 = {
        lock_1,lock_2,lock_3
    };

    int button_2_index = 0;

    for (auto& video : *video_list) {
        QString img = video.get_img();
        if (img != NULL){
            QString imagePath = img;
            QString buttonStyleSheet = QString("QPushButton { "
                                               "border: 2px solid #696666;"
                                               "border-radius: 10px;"
                                               "background-image: url(%1); " // %1 是参数占位符
                                               "background-position: center; "
                                               "background-repeat: no-repeat; "
                                               "background-clip: border; "
                                               "border-radius: 10px; "
                                               "}").arg(imagePath);

            buttons_2[button_2_index]->setStyleSheet(buttonStyleSheet);
        }
        else{
            buttons_2[button_2_index]->setStyleSheet(button_sheet_one);
            // 从资源文件加载图标
            QIcon icon(":/icon/plus.png");

            // 设置按钮的大小和图标
            icon = icon.pixmap(QSize(40, 40));
            buttons_2[button_2_index]->setIcon(icon);
            buttons_2[button_2_index]->setIconSize(QSize(40, 40));

        }
        button_2_index += 1;
    }
    videoWidget = new PlayerWidget();
    videoTest = new QMediaPlayer();
    surface = new MyVideoSurface();
    videoTest->setVideoOutput(surface);
    connect(surface, &MyVideoSurface::frameAvailable, this, &Widget::saveCover);


}

Widget::~Widget()
{
    delete ui;
}

video_item::video_item(QString url, QString img, QString t) {
    URL = url;
    image = img;
    time = t;
}

// 析构函数的实现
video_item::~video_item() {
    // 在这里进行清理工作，如果有的话
}


// 获取 URL 的函数实现
QString video_item::get_URL() {
    return URL;
}

// 获取图像的函数实现
QString video_item::get_img() {
    return image;
}

// 获取时间的函数实现
QString video_item::get_Time() {
    return time;
}

// 更改时间
void video_item::set_img( QString image) {
    this->image = image;
}

void video_item::set_URL( QString url) {
    this->URL = url;
}





