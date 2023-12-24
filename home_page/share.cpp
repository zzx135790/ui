#include "share.h"
#include "ui_share.h"

share::share(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::share)
{
    ui->setupUi(this);

    QLabel *label_14 = findChild<QLabel*>("label_14");

    if (label_14) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 40; // 你想要的新的宽度
        int newHeight = 40; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_14->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_14->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_17 = findChild<QLabel*>("label_17");

    if (label_17) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 40; // 你想要的新的宽度
        int newHeight = 40; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_17->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_17->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_20 = findChild<QLabel*>("label_20");

    if (label_20) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 40; // 你想要的新的宽度
        int newHeight = 40; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_20->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_20->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_26 = findChild<QLabel*>("label_26");

    if (label_26) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 40; // 你想要的新的宽度
        int newHeight = 40; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_26->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_26->setFixedSize(newWidth, newHeight);
    }

    QLabel *label_23 = findChild<QLabel*>("label_23");

    if (label_14) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 40; // 你想要的新的宽度
        int newHeight = 40; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_23->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_23->setFixedSize(newWidth, newHeight);
    }


    QLabel *label_29 = findChild<QLabel*>("label_29");

    if (label_29) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 40; // 你想要的新的宽度
        int newHeight = 40; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_29->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_29->setFixedSize(newWidth, newHeight);
    }

    QLabel *label = findChild<QLabel*>("label");

    if (label) {
        // 加载图标
        QPixmap originalPixmap(":/icon/search.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 20; // 你想要的新的宽度
        int newHeight = 20; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label->setFixedSize(newWidth, newHeight);
    }



    QLabel *label_3 = findChild<QLabel*>("label_3");

    if (label_3) {
        // 加载图标
        QPixmap originalPixmap(":/icon/blue.png");

        // 设置 QLabel 的大小

        // 指定新的宽度和高度，按比例缩放图像
        int newWidth = 30; // 你想要的新的宽度
        int newHeight = 30; // 你想要的新的高度

        QPixmap scaledPixmap = originalPixmap.scaled(newWidth, newHeight, Qt::KeepAspectRatio);

        // 将缩放后的图标设置给 QLabel
        label_3->setPixmap(scaledPixmap);
        // 设置 QLabel 的大小
        label_3->setFixedSize(newWidth, newHeight);
    }

    QString button_sheet_three = "QPushButton {"
                                 "border-radius: 8px;" // 普通状态下的边框圆角
                                 "background-color: #232323;"
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

