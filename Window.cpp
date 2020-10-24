#include <iostream>
#include "Window.h"

Window::Window(QWidget* parent) :QMainWindow(parent) {
    tableWidget = new QTableWidget(10,10,this);
    tableWidget->setGeometry(0,0,1080,330);

    for (int i =0; i<=9; i++) {
        for (int j =0; j<=9; j++){
            Cells* cell = new Cells(0,i,j,tableWidget);
            c.push_back(cell);
        }
    }

    sum = new Sum(cc, tableWidget);
    max = new Max(cc,tableWidget);
    min = new Min(cc,tableWidget);
    media = new Media(cc,tableWidget);

    this->setFixedSize(1030,325);
    this->setWindowTitle("Foglio di Calcolo");


    sumT = new QTextEdit("Somma:");
    sumT->setAutoFillBackground(true);
    sumT->setAlignment(Qt::AlignCenter);
    sumT->setReadOnly(true);
    tableWidget->setCellWidget(8,6,sumT);

    maxT = new QTextEdit("Massimo:");
    maxT->setAutoFillBackground(true);
    maxT->setAlignment(Qt::AlignCenter);
    maxT->setReadOnly(true);
    tableWidget->setCellWidget(8,7,maxT);

    minT = new QTextEdit("Minimo:");
    minT->setAutoFillBackground(true);
    minT->setAlignment(Qt::AlignCenter);
    minT->setReadOnly(true);
    tableWidget->setCellWidget(8,8,minT);

    mediaT = new QTextEdit("Media:");
    mediaT->setAutoFillBackground(true);
    mediaT->setAlignment(Qt::AlignCenter);
    mediaT->setReadOnly(true);
    tableWidget->setCellWidget(8,9,mediaT);


    sumCell = new QTextEdit();
    sumCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 6, sumCell);
    sumCell->setReadOnly(true);
    maxCell = new QTextEdit();
    maxCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 7, maxCell);
    maxCell->setReadOnly(true);
    minCell = new QTextEdit();
    minCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 8, minCell);
    minCell->setReadOnly(true);
    mediaCell = new QTextEdit();
    mediaCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 9, mediaCell);
    mediaCell->setReadOnly(true);

    connect(tableWidget, SIGNAL(cellChanged(int,int )), this, SLOT(cellChanged(int,int)));

}

void Window::cellChanged(int row, int column) {
    double s = tableWidget->item(row,column)->text().toDouble();

    for (auto it : c){
        if (it->getRow() == row && it->getColumn() == column && !it->getRegistered()){
            sum->putCells(it);
            max->putCells(it);
            min->putCells(it);
            media->putCells(it);
            it->setRegistered(true);
            it->registerO(sum);
            it->registerO(max);
            it->registerO(min);
            it->registerO(media);
            it->setValue(s);
        }
        else if (it->getRow() == row && it->getColumn() == column){
            it->setValue(s);
        }
    }

}

    sumCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 6, sumCell);
    sumCell->setReadOnly(true);
    maxCell = new QTextEdit();
    maxCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 7, maxCell);
    maxCell->setReadOnly(true);
    minCell = new QTextEdit();
    minCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 8, minCell);
    minCell->setReadOnly(true);
    mediaCell = new QTextEdit();
    mediaCell->setPlainText(QString::number(0));
    tableWidget->setCellWidget(9, 9, mediaCell);
    mediaCell->setReadOnly(true);
    
    connect(tableWidget, SIGNAL(cellChanged(int,int )), this, SLOT(cellChanged(int,int)));

}

void Window::cellChanged(int row, int column) {
    double s = tableWidget->item(row,column)->text().toDouble();
    for (auto it : c){
        if (it->getRow() == row && it->getColumn() == column){
            it->setValue(s);
        }
    }

}

    double sum_value = sum->op(c);
    string a = to_string(sum_value);
    sumCell = new QTextEdit();
    sumCell->setPlainText(QString::number(sum_value));
    tableWidget->setCellWidget(8, 2, sumCell);
    sumCell->setReadOnly(true);

    for (auto it :c) {
        connect(it->getCell(), SIGNAL(textChanged()), this, SLOT(cellChanged()));
    }

}

void Window::cellChanged() {

}
