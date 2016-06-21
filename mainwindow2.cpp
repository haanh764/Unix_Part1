#include "mainwindow2.h"
#include "ui_mainwindow2.h"
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

MainWindow2::MainWindow2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow2)
{
    ui->setupUi(this);

    QStringList CompletionList;
    CompletionList << "acn";
    StringCompleter = new QCompleter(CompletionList,this);
    StringCompleter->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(StringCompleter);

    //use a model
    ModelCompleter = new QCompleter(this);
    ModelCompleter->setModel(new QDirModel(ModelCompleter));
    ui->lineEdit_5->setCompleter(ModelCompleter);

}

MainWindow2::~MainWindow2()
{
    delete ui;
}

void MainWindow2::on_pushButton_clicked()
{
    QProcess *process = new QProcess;
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/p1.sh" << ui->lineEdit_5->text() << ui->lineEdit->text());
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/p2.sh" << ui->lineEdit_5->text() << ui->lineEdit_2->text());
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/p3.sh" << ui->lineEdit_5->text() << ui->lineEdit_3->text());
    process->start("/bin/bash", QStringList() << "/home/jiji/UnixCode/p4.sh" << ui->lineEdit_5->text() << ui->lineEdit_4->text());


    process->waitForBytesWritten();
    process->waitForFinished();

    QString output(process->readAllStandardOutput());
    ui->textEdit->setPlainText(output);

}
