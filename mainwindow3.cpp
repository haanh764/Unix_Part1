#include "mainwindow3.h"
#include "ui_mainwindow3.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <fstream>
#include <QString>
#include <QFileDialog>
#include <QProcess>
#include <QDebug>
#include <QtWidgets>
#include <QStringList>

MainWindow3::MainWindow3(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow3)
{
    ui->setupUi(this);

     //use a model
    ModelCompleter = new QCompleter(this);
    ModelCompleter->setModel(new QDirModel(ModelCompleter));
    ui->lineEdit->setCompleter(ModelCompleter);
}

MainWindow3::~MainWindow3()
{
    delete ui;
}

void MainWindow3::on_pushButton_clicked()
{
    QProcess *process = new QProcess;

    if (ui->radioButton->isChecked()){
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/sortBySize.sh" << ui->lineEdit->text());
    }
    if (ui->radioButton_2->isChecked()){
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/sortByname.sh" << ui->lineEdit->text());
    }
    if (ui->radioButton_3->isChecked()){
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/sortByctime.sh" << ui->lineEdit->text());
    }

    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit->setPlainText(output);
}
