#ifndef SHARE_H
#define SHARE_H

#include <QWidget>

namespace Ui {
class share;
}

class share : public QWidget
{
    Q_OBJECT

public:
    // Constructor for initializing the share widget
    explicit share(QWidget *parent = nullptr);
    ~share();

signals:
    // Signal for returning to the main page
    void back(QWidget *close);

private slots:
    // Slot for handling the return signal
    void on_return_2_clicked();

private:
    // UI page
    Ui::share *ui;
};

#endif // SHARE_H
