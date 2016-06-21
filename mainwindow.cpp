#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow2.h"
#include "ui_mainwindow2.h"
#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include <QFileDialog>
#include <QtCore>
#include <QtGui>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    //MainWindow2 w2;
    w2 =new MainWindow2(this);
    w2->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    //MainWindow3 w3;
    w3 =new MainWindow3(this);
    w3->show();
}
