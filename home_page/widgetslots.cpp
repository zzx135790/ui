#include "widget.h"
#include "video.h"
#include <QFileDialog>
#include <QImage>
#include <QDate>

void Widget::changeList(){

    QString button_sheet_one = "QPushButton {"
                               "border: 2px dashed #696666;"
                               "border-radius: 10px;"
                               "background-color: #232323;"
                               "}"
                               "QPushButton:hover {"
                               "border: 2px dashed #696666;" // Modify the border color while hovering

                               "border-radius: 10px;"
                               "background-color: #3C3C3C;"
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #696666;" // Change the background color when pressed

                               "border-radius: 10px;"
                               "background-color: #191919;"
                               "}";

    QString button_sheet_two = "QPushButton {"
                               "border: 2px solid #FAF9F6;" // Border style in normal state

                               "border-radius: 8px;"
                               "color: #ffffff"
                               "}"
                               "QPushButton:hover {"
                               "border-color: #FAF9F6;"
                               "background-color: #3C3C3C;"
                               "color: #ffffff"
                               "}"
                               "QPushButton:pressed {"
                               "border-width: 3px;" // Increase the border width when pressed

                               "background-color: #191919;"
                               "color: #ffffff"
                               "}";

    QString button_sheet_five = "QPushButton {"
                                "border: 2px solid #539ec6;"
                                "border-radius: 8px;"
                                "color: #ffffff"
                                "}"
                                "QPushButton:hover {"
                                "border-color: #0b6a9b;"
                                "background-color: #3C3C3C;"
                                "color: #ffffff"
                                "}"
                                "QPushButton:pressed {"
                                "border-width: 3px;"
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

    QVector<QString> dates;

    // Get today's date
    QDate currentDate = QDate::currentDate();

    show_list->clear();
    // 生成向前推14天的日期
    for (int i = 0; i < 14; ++i) {
        QDate date = currentDate.addDays(-i);
        QString dateString = date.toString("yyyy-MM-dd");
        dates.append(dateString);
    }

    // Generates a date pushed forward 14 days

    for (const QString &date : dates) {
        bool found = false;

        for (video_item& video : *video_list) {
            if (video.get_Time() == date) {
                show_list->append(video);
                found = true;
            }
        }

        if (!found) {
            // If no match is found, a video object with an empty date is created and added to the new list

            video_item video_item ("", "", "");
            show_list->append(video_item);
        }
    }

//    std::reverse(show_list->begin(), show_list->end());


    int buttonIndex = 0;
    for (auto& video : *show_list) {

        signalMapper = new QSignalMapper(this);

        QPushButton* button = buttons[buttonIndex];


        if(video.get_img() != NULL){

            QString url = video.get_URL();

            disconnect(button, &QPushButton::clicked, 0, 0);

            connect(button, &QPushButton::clicked, [this, url]() {
                // The button click event is handled here, using the information of the video object
                post_url(url);
            });


            QString day = video.get_Time().mid(8, 2); // Starting at index 8, cut a substring of length 2
            QString iconPath = QString(":/icon/%1.png").arg(day);

            // Load ICONS from resource files
            QIcon icon(iconPath);

            // Set the button size and icon
            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_five);
        }
        else if(video.get_img() == NULL && buttonIndex == 0){

            QIcon icon(":/icon/plus.png");
            disconnect(button, &QPushButton::clicked, 0, 0);
            connect(button,SIGNAL(clicked()),this,SLOT(addVideo()));

            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
        else{


            QIcon icon(":/icon/lock.png");


            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
        buttonIndex += 1;
    }

    if(buttonIndex < 14){
        for (int i = buttonIndex; i < 14; ++i) {

            QIcon icon(":/icon/plus.png");
            QPushButton* button = buttons[i];

            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
    }

    for (auto it = show_list->begin(); it != show_list->end();) {
        if (it->get_img().isEmpty()) {
            it = show_list->erase(it); // Delete the objects that meet the conditions

        } else {
            ++it;
        }
    }


    if (show_list->size() > 3) {
        show_list->erase(show_list->begin() + 3, show_list->end()); // Delete all items from the fourth item to the end

    }


    QPushButton *lock_1 = findChild<QPushButton*>("plus");
    QPushButton *lock_2 = findChild<QPushButton*>("lock_1");
    QPushButton *lock_3 = findChild<QPushButton*>("lock_2");

    QList<QPushButton*> buttons_2 = {
        lock_1,lock_2,lock_3
    };

    int button_2_index = 0;

    for (auto& video : *show_list) {
        QString img = video.get_img();
        if (img != NULL){
            QString imagePath = img;
            QString url = video.get_URL();
            disconnect(buttons_2[button_2_index], &QPushButton::clicked, 0, 0);
            connect(buttons_2[button_2_index], &QPushButton::clicked, [this, url]() {
                // The button click event is handled here, using the information of the video object
                post_url(url);
            });

            QFileInfo fileInfo(imagePath);
            QString fileName = fileInfo.baseName(); // 获取不带后缀的文件名

            QPixmap originalPixmap(imagePath);

            int targetHeight = 200;

            // Scale the image by height
            QPixmap scaledPixmap = originalPixmap.scaledToHeight(targetHeight);

            QString rootDirPath = QCoreApplication::applicationDirPath();

            // Build a temporary folder path relative to the root directory
            QString tempDirPath = rootDirPath + "/temp"; // Adjust the path as needed

            QDir tempDir(tempDirPath);

            qDebug() << tempDirPath ;

            if (!tempDir.exists()) {
                qDebug() << "Temp directory does not exist!";
                // Try creating a temporary folder
                if (!tempDir.mkpath(".")) {
                    qDebug() << "Failed to create temp directory!";
                    // Handle the situation where a temporary folder cannot be created
                    return ;
                }
            }

            // Creates a temporary file in the specified temporary folder
            QTemporaryFile tempFile(tempDir.path() + "/tempImage" + fileName +".png");

            if (!scaledPixmap.save(tempDir.path() + "/tempImage" + fileName +".png")) {
                qDebug() << "Failed to save image!";
                // Handle a save failure
                return ;
            } else {
                qDebug() << "Image saved successfully to:" << tempDir.path() + "/tempImage" + fileName +".png";
            }
            buttons_2[button_2_index]->setStyleSheet("");
            buttons_2[button_2_index]->setIcon(QIcon()); // pass in an empty QIcon
            QString buttonStyleSheet = QString("QPushButton { "
                                               "border: 2px dashed #696666;"
                                               "border-radius: 10px;"
                                               "background-image: url(%1); " // %1
                                               "background-position: center;"
                                               "background-position: center; "
                                               "background-repeat: no-repeat; "
                                               "background-clip: border; "
                                               "border-radius: 10px; "
                                               "}"
                                               "QPushButton:hover {"
                                               "background-image: url(%1); "
                                               "background-position: center;"
                                               "border: 2px solid #696666;"
                                               "border-radius: 10px;"
                                               "}"
                                               "QPushButton:pressed {"
                                               "border: 3px solid #696666;"
                                               "border-radius: 10px;"
                                               "}").arg(tempDir.path() + "/tempImage" + fileName +".png");

            buttons_2[button_2_index]->setStyleSheet(buttonStyleSheet);
        }
        else{
            buttons_2[button_2_index]->setStyleSheet(button_sheet_one);

            QIcon icon(":/icon/plus.png");


            icon = icon.pixmap(QSize(40, 40));
            buttons_2[button_2_index]->setIcon(icon);
            buttons_2[button_2_index]->setIconSize(QSize(40, 40));

        }
        button_2_index += 1;
    }

    if(button_2_index < 3){
        for (int i = button_2_index; i < 3; ++i) {

            QIcon icon(":/icon/lock.png");
            QPushButton* button = buttons_2[i];

            icon = icon.pixmap(QSize(40, 40));
            button->setIcon(icon);
            button->setIconSize(QSize(40, 40));

            button->setStyleSheet(button_sheet_one);
        }
    }

    this->update();


    for (video_item& video : *show_list) {
        qDebug() << "Title:" << video.get_img() << "Date:" << video.get_Time();
    }

    for (video_item& video : *video_list) {
        qDebug() << "Title:" << video.get_img() << "Date:" << video.get_Time();
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



    qDebug() << cover.exists();
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
        this->update();
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
        // Set widget2 to the same location as widget1
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

    QPoint currentPos = close->pos();
    int x = currentPos.x();
    int y = currentPos.y();
    this->move(x, y);
    close->close();
    this->show();
}

void Widget::post_url(QString url)
{
    qDebug() << "URL:" << url;
    videoWidget->show();
    QPalette currentPal(this->palette());
    QPoint currentPos = this->pos();
    QSize currentPageSize = this->size();
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

    qDebug() << "File exist, performing the operation...";
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true); // Set automatic formatting for easier reading


    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("mediaItems");

    for (auto& item : *video_list) {
        xmlWriter.writeStartElement("mediaItem");
        xmlWriter.writeTextElement("imagePath", item.get_img());
        xmlWriter.writeTextElement("createTime", item.get_Time());
        xmlWriter.writeTextElement("videoPath", item.get_URL());
        xmlWriter.writeEndElement(); // mediaItem
    }

    xmlWriter.writeEndElement(); // mediaItems
    xmlWriter.writeEndDocument();

    file.close();
    qDebug() << "Write to the file sucssessfully, performing the operation...";

}
