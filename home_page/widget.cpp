#include "widget.h"
#include "video.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    ,video_list(new QVector<video_item>)
    ,show_list(new QVector<video_item>)
{
    ui->setupUi(this);
    this->widget2 =new share;
    connect(this->widget2,SIGNAL(back()),this,SLOT(comeBackToPrev()));

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

    share_3->setStyleSheet(button_sheet_three);
    user_3->setStyleSheet(button_sheet_three);
    shoot->setStyleSheet(button_sheet_four);

    QFile file_org("./data.xml");

    if (!file_org.exists()) {
        // 文件不存在，执行你的函数或操作
        writeXmlToFile();
        qDebug() << "File doesn't exist, performing the operation...";
    } else {
        // 文件存在，不执行操作
        qDebug() << "File already exists, skipping the operation...";
    }



    //读取文件内容

    QFile file("./data.xml");
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

    if (video_list->size() > 14) {
        std::reverse(video_list->end() - 14, video_list->end());
        video_list->erase(video_list->begin(), video_list->end() - 14);
    } else {
        std::reverse(video_list->begin(), video_list->end());
    }



    int buttonIndex = 0;

    for (auto& video : *video_list) {

        signalMapper = new QSignalMapper(this);

        QPushButton* button = buttons[buttonIndex];

        if(video.get_img() != NULL && buttonIndex < 3){

            QString url = video.get_URL();
            QPalette currentPal(this->palette());
            QSize currentPageSize = this->size();

            connect(button, &QPushButton::clicked, [this, url,currentPageSize]() {
                // 在这里处理按钮点击事件，使用video对象的信息
                post_url(url,currentPageSize);
            });

            // 从资源文件加载图标
            QIcon icon(":/icon/plus.png");

            // 设置按钮的大小和图标
            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_five);
        }
        else if(video.get_img() == NULL && buttonIndex < 3){


            // 从资源文件加载图标
            QIcon icon(":/icon/lock.png");

            // 设置按钮的大小和图标
            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_five);
        }
        else if(video.get_img() != NULL && buttonIndex >= 3){

            QString url = video.get_URL();
            QPalette currentPal(this->palette());
            QSize currentPageSize = this->size();
            connect(button, &QPushButton::clicked, [this, url,currentPageSize]() {
                // 在这里处理按钮点击事件，使用video对象的信息
                post_url(url,currentPageSize);
            });

            // 从资源文件加载图标
            QIcon icon(":/icon/plus.png");

            // 设置按钮的大小和图标
            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
        else{

            // 从资源文件加载图标
            QIcon icon(":/icon/lock.png");

            // 设置按钮的大小和图标
            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
        buttonIndex += 1;
    }

    if (video_list->size() > 3) {
        video_list->erase(video_list->begin() + 3, video_list->end()); // 删除从第四项开始到末尾的所有项
    }



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

void Widget::on_share_3_clicked()
{   
    if (this->isVisible()) {
        QPalette currentPal(this->palette());
        QSize currentPageSize = this->size();
        // 设置 widget2 的位置为与 widget1 相同
        QPoint currentPos = this->pos();
        int x = currentPos.x();
        int y = currentPos.y();
        this->widget2->move(x, y);
        this->hide();
        this->widget2->resize(currentPageSize);
        this->widget2->setPalette(currentPal);
        this->widget2->show();
    } else {
        QPalette widget2Pal(this->widget2->palette());
        this->widget2->hide();
        this->setPalette(widget2Pal);
        this->show();
    }
}

void Widget::comeBackToPrev()
{
    // 设置 widget2 的位置为与 widget1 相同
    QPoint currentPos = this->widget2->pos();
    int x = currentPos.x();
    int y = currentPos.y();
    this->widget2->move(x, y);
    this->widget2->hide();
    this->show();
}

void Widget::post_url(QString url,QSize currentPageSize)
{
    qDebug() << "URL:" << url;
    videoWidget->show();
    QPalette currentPal(this->palette());
    QPoint currentPos = this->pos();
    int x = currentPos.x();
    int y = currentPos.y();
    connect(this,SIGNAL(video_url(QString ,QPalette ,QSize,int,int)),videoWidget,SLOT(SetResource(QString,QPalette ,QSize,int,int)));
    emit video_url(url,currentPal,currentPageSize,x,y);
}

void Widget::handleClick()
{
    this->hide();

}


void Widget::writeXmlToFile() {
    QFile file("./data.xml"); // 替换为你想要保存的文件路径

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // 文件打开失败，处理错误
        qDebug() << "文件打开失败";
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true); // 可选，设置自动格式化以便更易读

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("mediaItems");

    // 这里准备了一个示例数据列表，你可以使用自己的数据
    QList<QStringList> mediaItems = {
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-01", "/Users/pamper/Desktop/test1/avi"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-02", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-03", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-04", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-05", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-06", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-07", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-08", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-09", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-10", "/Users/pamper/Desktop"},
        {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-11", "F:/FFOutput/test.wmv"},
        {"", "2023-12-12", "/Users/pamper/Desktop/test1.avi"},
        {":/icon/user_img/user1.png", "2023-12-13", "/Users/pamper/Desktop/test1.avi"},
        {":/icon/user_img/user1.png", "2023-12-13", "/Users/pamper/Desktop/test1.avi"},
    };

    for (const auto& item : mediaItems) {
        xmlWriter.writeStartElement("mediaItem");
        xmlWriter.writeTextElement("imagePath", item.at(0));
        xmlWriter.writeTextElement("createTime", item.at(1));
        xmlWriter.writeTextElement("videoPath", item.at(2));
        xmlWriter.writeEndElement(); // mediaItem
    }

    xmlWriter.writeEndElement(); // mediaItems
    xmlWriter.writeEndDocument();

    file.close(); // 关闭文件
}




