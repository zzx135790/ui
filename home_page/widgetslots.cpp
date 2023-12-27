#include "widget.h"
#include "video.h"
#include <QFileDialog>
#include <QImage>
#include <QDate>

void Widget::changeList(){
    // Define button style sheets
    QString button_sheet_one = "QPushButton {"
                               "border: 2px dashed #696666;"
                               "border-radius: 10px;"
                               "background-color: #232323;"
                               "}"
                               "QPushButton:hover {"
                               "border: 2px dashed #696666;" // Modify border color when hovered
                               "border-radius: 10px;"
                               "background-color: #3C3C3C;"
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #696666;" // Modify background color when pressed
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
                               "border-width: 3px;" // Increase border width when pressed
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

    // Find QPushButton widgets
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

    // Create a list of QPushButton pointers
    QList<QPushButton*> buttons = {
        view_29, view_30, view_31, view_32, view_33,
        view_34, view_35, view_36, view_37, view_38,
        view_39, view_40, view_41, view_42
    };

    QVector<QString> dates;

    // Get today's date
    QDate currentDate = QDate::currentDate();

    show_list->clear();

    // Generate dates for the past 14 days
    for (int i = 0; i < 14; ++i) {
        QDate date = currentDate.addDays(-i);
        QString dateString = date.toString("yyyy-MM-dd");
        dates.append(dateString);
    }

    // Iterate through dates and populate show_list
    for (const QString &date : dates) {
        bool found = false;

        for (video_item& video : *video_list) {
            if (video.get_Time() == date) {
                show_list->append(video);
                found = true;
            }
        }

        if (!found) {
            // If no matching item is found, create a video object with an empty date and add it to the new list
            video_item video_item ("", "", date);
            show_list->append(video_item);
        }
    }

    int buttonIndex = 0;

    // Update buttons based on the content of show_list
    for (auto& video : *show_list) {
        QPushButton* button = buttons[buttonIndex];

        if (video.get_img() != NULL){
            // Handle buttons with video images
            QString url = video.get_URL();

            disconnect(button, &QPushButton::clicked, 0, 0);

            connect(button, &QPushButton::clicked, [this, url]() {
                // Handle button click event using video object information
                post_url(url);
            });

            QString day = video.get_Time().mid(8, 2); // Extract a substring starting from index 8 with a length of 2
            QString iconPath = QString(":/icon/%1.png").arg(day);

            // Load the icon from the resource file
            QIcon icon(iconPath);

            // Set button size and icon
            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_five);
        }
        else if(video.get_img() == NULL && buttonIndex == 0){
            // Handle the first button without an image
            QIcon icon(":/icon/plus.png");
            disconnect(button, &QPushButton::clicked, 0, 0);
            connect(button, SIGNAL(clicked()), this, SLOT(addVideo()));

            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
        else{
            // Handle buttons without images (except the first button)
            QString day = video.get_Time().mid(8, 2); // Extract a substring starting from index 8 with a length of 2
            QString iconPath = QString(":/icon/%1.png").arg(day);
            QIcon icon(iconPath);

            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
        buttonIndex += 1;
    }

    // If buttonIndex is less than 14, fill the remaining buttons
    if(buttonIndex < 14){
        for (int i = buttonIndex; i < 14; ++i) {
            QString day = dates[i].mid(8, 2); // Extract a substring starting from index 8 with a length of 2
            QString iconPath = QString(":/icon/%1.png").arg(day);
            QIcon icon(iconPath);

            QPushButton* button = buttons[i];

            icon = icon.pixmap(QSize(16, 16));
            button->setIcon(icon);
            button->setIconSize(QSize(16, 16));

            button->setStyleSheet(button_sheet_two);
        }
    }

    // Remove objects with empty images from show_list
    for (auto it = show_list->begin(); it != show_list->end();) {
        if (it->get_img().isEmpty()) {
            it = show_list->erase(it); // Erase objects that meet the condition
        } else {
            ++it;
        }
    }

    // If the size of show_list is greater than 3, remove all items starting from the fourth item
    if (show_list->size() > 3) {
        show_list->erase(show_list->begin() + 3, show_list->end());
    }

    // Find another set of buttons (buttons_2) and update their styles and icons
    QPushButton *lock_1 = findChild<QPushButton*>("plus");
    QPushButton *lock_2 = findChild<QPushButton*>("lock_1");
    QPushButton *lock_3 = findChild<QPushButton*>("lock_2");

    QList<QPushButton*> buttons_2 = {
        lock_1, lock_2, lock_3
    };

    int button_2_index = 0;

    for (auto& video : *show_list) {
        QString img = video.get_img();
        if (img != NULL){
            QString imagePath = img;
            QString url = video.get_URL();
            disconnect(buttons_2[button_2_index], &QPushButton::clicked, 0, 0);
            connect(buttons_2[button_2_index], &QPushButton::clicked, [this, url]() {
                // Handle button click event using video object information
                post_url(url);
            });

            QFileInfo fileInfo(imagePath);
            QString fileName = fileInfo.baseName(); // Get the base name of the file without the extension

            QPixmap originalPixmap(imagePath);

            int targetHeight = 200;

            // Scale the image by height
            QPixmap scaledPixmap = originalPixmap.scaledToHeight(targetHeight);

            QString rootDirPath = QCoreApplication::applicationDirPath();

            // Build the temporary folder path relative to the root directory
            QString tempDirPath = rootDirPath + "/temp"; // Adjust the path as needed

            QDir tempDir(tempDirPath);

            qDebug() << tempDirPath ;

            if (!tempDir.exists()) {
                qDebug() << "Temporary directory does not exist!";
                // Try to create the temporary folder
                if (!tempDir.mkpath(".")) {
                    qDebug() << "Unable to create the temporary directory!";
                    // Handle the case where the temporary folder cannot be created
                    return ;
                }
            }

            // Create a temporary file in the specified temporary folder
            QTemporaryFile tempFile(tempDir.path() + "/tempImage" + fileName +".png");

            if (!scaledPixmap.save(tempDir.path() + "/tempImage" + fileName +".png")) {
                qDebug() << "Failed to save the image!";
                // Handle the save failure
                return ;
            } else {
                qDebug() << "Image successfully saved to: " << tempDir.path() + "/tempImage" + fileName +".png";
            }

            buttons_2[button_2_index]->setStyleSheet("");
            buttons_2[button_2_index]->setIcon(QIcon()); // Set to an empty QIcon
            QString buttonStyleSheet = QString("QPushButton { "
                                               "border: 2px dashed #696666;"
                                               "border-radius: 10px;"
                                               "background-image: url(%1); "
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

    // If button_2_index is less than 3, fill the remaining buttons
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

    // Debug print the content of show_list and video_list
    for (video_item& video : *show_list) {
        qDebug() << "Title:" << video.get_img() << "Date:" << video.get_Time();
    }

    for (video_item& video : *video_list) {
        qDebug() << "Title:" << video.get_img() << "Date:" << video.get_Time();
    }
}


void Widget::addVideo(){
    // Open the file selection dialog
    QString resource = QFileDialog::getOpenFileName(this, tr("Choose today's video"), "", tr("Video Files (*.wmv)"));
    QFile video_ori(resource);

    // Error check
    if (resource.isEmpty() || !video_ori.exists()) {
        return;
    }

    // Get the video cover using a custom MyVideoSurface

    videoTest->setMedia(QUrl::fromLocalFile(resource)); // Set the resource and open it
    videoTest->play(); // Play the video to emit signals
    loop.exec(); // Wait for the image to be saved to the corresponding directory
    QFile cover(cover_path + date + ".png");

    //    qDebug() << cover.exists();

    if (cover.exists()) {
        QDir video_des(video_path); // Check if the video save location exists
        QFile::remove(video_path + date + ".wmv"); // Delete the original video
        //        qDebug()<<"delete:"<<test;
        if (!video_des.exists() || !video_ori.copy(video_path + date + ".wmv")) { // Copy the video to the specified directory
            return;
        }
        if (video_list->isEmpty()) { // If the video list is empty, add it directly
            video_item new_item(video_path + date + ".wmv", cover_path + date + ".png", date);
            video_list->append(new_item);
        } else {
            auto last = std::prev(video_list->end());

            if (!video_list->isEmpty() && last->get_Time() == date) { // Replace today's video if it exists
                last->set_URL(video_path + date + ".wmv");
                last->set_img(cover_path + date + ".png");
            } else { // Otherwise, add it to the end
                video_item new_item(video_path + date + ".wmv", cover_path + date + ".png", date);
                video_list->append(new_item);
            }
        }

        emit list_change(); // Emit a signal for re-rendering
    }
}

// Receive video frames and save them as covers
void Widget::saveCover(const QImage &frame) {

    frame.save(cover_path + date + ".png", "PNG"); // Save to the specified location
    videoTest->stop(); // Pause the video
    videoTest->setMedia(QMediaContent()); // Release the original video resource
    loop.quit(); // Return the signal, indicating that the cover has been saved
}

void Widget::on_share_3_clicked()
{
    if (this->isVisible()) {
        QPalette currentPal(this->palette());
        QSize currentPageSize = this->size();
        // Get the current window's position
        QPoint currentPos = this->pos();
        int x = currentPos.x();
        int y = currentPos.y();
        // Move widget2 to the same position as widget1
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
    // Get the position of the window to be closed
    QPoint currentPos = close->pos();
    int x = currentPos.x();
    int y = currentPos.y();
    // Move the current window to the same position as the closing window
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
    // Establish a signal-slot connection to pass the video URL to videoWidget
    connect(this, SIGNAL(video_url(QString, QPalette, QSize, int, int)), videoWidget, SLOT(SetResource(QString, QPalette, QSize, int, int)));
    // Establish a signal-slot connection to handle the back operation
    connect(videoWidget, SIGNAL(back(QWidget*)), this, SLOT(comeBackToPrev(QWidget*)));
    // Send the video_url signal to pass the URL and window parameters
    emit video_url(url, currentPal, currentPageSize, x, y);
}

void Widget::handleClick()
{
    this->hide();
}

void Widget::writeXmlToFile() {
    QDir cover(QFileInfo(cover_path + "1").absoluteDir());
    QDir vdo(QFileInfo(video_path + "1").absoluteDir());
    if (!cover.exists()) {
        cover.mkpath(".");
    }

    if (!vdo.exists()) {
        vdo.mkpath(".");
    }

    QFile file("./source/data.xml"); // Replace with the file path you want to save to

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        // File opening failed, handle the error
        qDebug() << "Failed to open the file";
        return;
    }

    qDebug() << "The file already exists, performing the operation...";
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true); // Set auto-formatting for easier readability

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
    qDebug() << "Successfully wrote to the file, performing the operation...";
}
