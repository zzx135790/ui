#include "widget.h"
#include "video.h"
#include <QFileDialog>
#include <QImage>
#include <QDate>

void Widget::changeList(){

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
//    QPushButton *view_all = findChild<QPushButton*>("view_all");

    QList<QPushButton*> buttons = {
        view_29, view_30, view_31, view_32, view_33,
        view_34, view_35, view_36, view_37, view_38,
        view_39, view_40, view_41, view_42
    };

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
}

void Widget::addVideo(){
    QString resource = QFileDialog::getOpenFileName(this, tr("Choose today video"), "", tr(" Video Files(*.wmv)"));
    QFile video_ori(resource);
    if (resource.isEmpty()||!video_ori.exists()) {
        return;
    }

    videoTest->setMedia(QUrl::fromLocalFile(resource));
    videoTest->setPosition(videoTest->duration()/2);
    videoTest->play();
    loop.exec();
    QFile cover(cover_path+date+".png");
    if (cover.exists()){
        QDir video_des(video_path);
        if (!video_des.exists()||!video_ori.copy(video_path+date+".wmv")){
            return ;
        }
        if (video_list->isEmpty()){
            video_item new_item(video_path+date+".wmv",cover_path+date+".png",date);
            video_list->append(new_item);
        }
        else {
            auto last = std::prev(video_list->end());
            if (!video_list->isEmpty()&&last->get_Time() == date){
                last->set_URL(video_path+date+".wmv");
                last->set_img(cover_path+date+".png");
            }
            else {
                video_item new_item(video_path+date+".wmv",cover_path+date+".png",date);
                video_list->append(new_item);
            }
        }
        emit list_change();
    }

}
void Widget::saveCover(const QImage &frame){
    frame.save(cover_path+date+".png","PNG");
    videoTest->stop();
    loop.quit();
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

void Widget::comeBackToPrev(QWidget *close)
{
    // 设置 widget2 的位置为与 widget1 相同
    QPoint currentPos = close->pos();
    int x = currentPos.x();
    int y = currentPos.y();
    this->move(x, y);
    close->close();
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
    connect(videoWidget,SIGNAL(back(QWidget*)),this,SLOT(comeBackToPrev(QWidget*)));
    emit video_url(url,currentPal,currentPageSize,x,y);
}

void Widget::handleClick()
{
    this->hide();

}


void Widget::writeXmlToFile() {
    QDir cover(QFileInfo(cover_path+"1").absoluteDir());
    QDir vdo(QFileInfo(video_path+"1").absoluteDir());
//    qDebug()<<QFileInfo("./source/img/1").absoluteDir();
    if (!cover.exists()){
        cover.mkpath(".");
//        qDebug()<<tem;
    }

    if (!vdo.exists()){
        vdo.mkpath(".");
        //        qDebug()<<tem;
    }

    QFile file("./source/data.xml"); // 替换为你想要保存的文件路径

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // 文件打开失败，处理错误
        qDebug() << "文件打开失败";
        return;
    }

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true); // 可选，设置自动格式化以便更易读

    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("mediaItems");

//    // 这里准备了一个示例数据列表，你可以使用自己的数据
//    QList<QStringList> mediaItems = {
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-01", "/Users/pamper/Desktop/test1/avi"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-02", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-03", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-04", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-05", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-06", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-07", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-08", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-09", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-10", "/Users/pamper/Desktop"},
//                                     {"/Users/pamper/Desktop/QT/home_page/user_img/user1.png", "2023-12-11", "F:/FFOutput/test.wmv"},
//                                     {"", "2023-12-12", "C:/Users/zzx123/Downloads/test2.wmv"},
//                                     {":/icon/user_img/user1.png", "2023-12-13", "C:/Users/zzx123/Downloads/test2.wmv"},
//                                     {":/icon/user_img/user1.png", "2023-12-13", "C:/Users/zzx123/Downloads/test2.wmv"},
//                                     };

//    for (const auto& item : mediaItems) {
//        xmlWriter.writeStartElement("mediaItem");
//        xmlWriter.writeTextElement("imagePath", item.at(0));
//        xmlWriter.writeTextElement("createTime", item.at(1));
//        xmlWriter.writeTextElement("videoPath", item.at(2));
//        xmlWriter.writeEndElement(); // mediaItem
//    }

    xmlWriter.writeEndElement(); // mediaItems
    xmlWriter.writeEndDocument();

    file.close(); // 关闭文件
}
