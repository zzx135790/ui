#include "video.h"
#include "ui_video.h"


int buttonTextState = 1;
QPushButton *numberButton = NULL;



Video::Video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Video)
{

    ui->setupUi(this);
    // 连接按钮的点击信号到槽函数
    numberButton = findChild<QPushButton*>("pushButton_13");
    connect(numberButton, &QPushButton::clicked, this, &Video::onNumberButtonClicked);
//    Widget *widget = new Widget();
//    connect(widget, &Widget::video_url, this, &Video::receiveURL);

    QPushButton *backButton = findChild<QPushButton*>("video_to_home_2");
    connect(backButton, &QPushButton::clicked, this, &Video::return_to_home);

}

Video::~Video()
{
    delete ui;
}

void Video::return_to_home()
{
    this->hide();
    widget->show();
}

//void Video::receiveURL(const QString &url, const QSize &size, const QPalette &currentPal) {

//    qDebug() << "Received URL in Page2: " << url;
//    this->resize(size);
//    this->setPalette(currentPal);
//    this->show();

//}


// 槽函数，用于处理按钮的点击事件
void Video::onNumberButtonClicked() {
    buttonTextState = (buttonTextState % 3) + 1; // 循环在 1、2、3 之间切换
    QString newText = QString::number(buttonTextState); // 将状态转换为字符串
    numberButton->setText(newText); // 设置按钮文本为新的状态值
}
