#include "widget.h"
#include "video.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QImage>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    // 获取屏幕的几何信息
    QDesktopWidget desktop;
    int screenWidth = desktop.width();
    int screenHeight = desktop.height();

    // 计算窗口的位置，使其居中显示
    int windowWidth = w.width();
    int windowHeight = w.height();

    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;
    w.setGeometry(x, y, windowWidth, windowHeight);

    // 添加黑色背景
    QPalette pal(w.palette());
    pal.setColor(QPalette::Background, Qt::black);
    w.setAutoFillBackground(true);
    w.setPalette(pal);

    w.show();
//    PlayerWidget video;
//    video.show();
    return a.exec();
}
