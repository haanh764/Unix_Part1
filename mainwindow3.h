#ifndef MAINWINDOW3_H
#define MAINWINDOW3_H

#include <QMainWindow>
#include <QCompleter>
#include <QDirModel>

namespace Ui {
class MainWindow3;
}

class MainWindow3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow3(QWidget *parent = 0);
    ~MainWindow3();

private slots:


    void on_pushButton_clicked();

private:
    Ui::MainWindow3 *ui;
    QCompleter *StringCompleter;
    QCompleter *ModelCompleter;
};

#endif // MAINWINDOW3_H
