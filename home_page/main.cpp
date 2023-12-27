#include "widget.h"
#include <QDesktopWidget>
#include <QApplication>
#include <QImage>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;

    // Get the screen's geometry information
    QDesktopWidget desktop;
    int screenWidth = desktop.width();
    int screenHeight = desktop.height();

    // Calculate the window's position to center it on the screen
    int windowWidth = w.width();
    int windowHeight = w.height();

    int x = (screenWidth - windowWidth) / 2;
    int y = (screenHeight - windowHeight) / 2;

    // Set the window's position and size
    w.setGeometry(x, y, windowWidth, windowHeight);

    // Add a black background
    QPalette pal(w.palette());
    pal.setColor(QPalette::Background, Qt::black);
    w.setAutoFillBackground(true);
    w.setPalette(pal);

    // Show the window
    w.show();

    // Start the application's event loop
    return a.exec();
}
