#include "share.h"
#include "ui_share.h"

share::share(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::share)
{
    ui->setupUi(this);

    QLabel *label_14 = findChild<QLabel*>("label_14");

    if (label_14) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 40; // The new width you desire
        int newHeight = 40; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_14->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_14->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_17 = findChild<QLabel*>("label_17");

    if (label_17) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 40; // The new width you desire
        int newHeight = 40; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_17->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_17->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_20 = findChild<QLabel*>("label_20");

    if (label_20) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 40; // The new width you desire
        int newHeight = 40; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_20->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_20->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_26 = findChild<QLabel*>("label_26");

    if (label_26) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 40; // The new width you desire
        int newHeight = 40; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_26->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_26->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_23 = findChild<QLabel*>("label_23");

    if (label_14) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 40; // The new width you desire
        int newHeight = 40; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_23->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_23->setFixedSize(newWidth, newHeight);
    }


    QLabel *label_29 = findChild<QLabel*>("label_29");

    if (label_29) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 40; // The new width you desire
        int newHeight = 40; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_29->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_29->setFixedSize(newWidth, newHeight);
    }

    QLabel *label = findChild<QLabel*>("label");

    if (label) {
        // Load icon
        QPixmap originalPixmap(":/icon/search.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 20; // The new width you desire
        int newHeight = 20; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label->setPixmap(scaledPixmap);
        // Set QLabel's size
        label->setFixedSize(newWidth, newHeight);
    }



    QLabel *label_3 = findChild<QLabel*>("label_3");

    if (label_3) {
        // Load icon
        QPixmap originalPixmap(":/icon/blue.png");

        // Set QLabel's size

        // Specify the new width and height, scaling the image proportionally
        int newWidth = 30; // The new width you desire
        int newHeight = 30; // The new height you desire

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // Set the scaled icon to the QLabel
        label_3->setPixmap(scaledPixmap);
        // Set QLabel's size
        label_3->setFixedSize(newWidth, newHeight);
    }

    QString button_sheet_three = "QPushButton {"
                                 "border-radius: 8px;" // Border radius for normal state
                                 "background-color: #232323;"
                                 "color: #ffffff"
                                 "}"
                                 "QPushButton:hover {"
                                 "border-color: #FAF9F6;" // Modify border color for hover state
                                 "background-color: #3C3C3C;"
                                 "color: #ffffff"
                                 "}"
                                 "QPushButton:pressed {"
                                 "border-width: 3px;" // Increase border width for pressed state
                                 "background-color: #191919;"
                                 "color: #ffffff"
                                 "}";



    QPushButton *return_2 = findChild<QPushButton*>("return_2");
    return_2->setStyleSheet(button_sheet_three);

    QPushButton *upload = findChild<QPushButton*>("upload");
    upload->setStyleSheet(button_sheet_three);

    QPushButton *invite_1 = findChild<QPushButton*>("invite_1");
    invite_1->setStyleSheet(button_sheet_three);

    QPushButton *invite_2 = findChild<QPushButton*>("invite_2");
    invite_2->setStyleSheet(button_sheet_three);

    QPushButton *invite_3 = findChild<QPushButton*>("invite_3");
    invite_3->setStyleSheet(button_sheet_three);

    QPushButton *invite_4 = findChild<QPushButton*>("invite_4");
    invite_4->setStyleSheet(button_sheet_three);

    QPushButton *invite_5 = findChild<QPushButton*>("invite_5");
    invite_5->setStyleSheet(button_sheet_three);

    QPushButton *invite_6 = findChild<QPushButton*>("invite_6");
    invite_6->setStyleSheet(button_sheet_three);

}

share::~share()
{
    delete ui;
}


void share::on_return_2_clicked()
{
    emit this->back(this);
}
