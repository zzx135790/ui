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
    explicit share(QWidget *parent = nullptr);
    ~share();

signals:
    void back(QWidget *close);

private slots:

    void on_return_2_clicked();

private:
    Ui::share *ui;
};

#endif // SHARE_H
