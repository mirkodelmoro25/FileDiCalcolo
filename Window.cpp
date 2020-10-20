#include "Window.h"

Window::Window(QWidget* parent) :QMainWindow(parent) {
    tableWidget = new QTableWidget(11,11,this);
    tableWidget->setGeometry(0,0,1125,365);

    Cells* cell = new Cells (23,3 ,3, tableWidget);
    Cells* cell2 = new Cells (10,4,6,tableWidget);
    
    c.push_back(cell);
    c.push_back(cell2);
    sum = new Sum(c, tableWidget);
    

    this->resize(1125,365);
    this->setWindowTitle("Foglio di Calcolo");






    sumT = new QTextEdit("Somma:");
    sumT->setAutoFillBackground(true);
    sumT->setAlignment(Qt::AlignCenter);
    sumT->setReadOnly(true);
    tableWidget->setCellWidget(7,2,sumT);

    maxT = new QTextEdit("Massimo:");
    maxT->setAutoFillBackground(true);
    maxT->setAlignment(Qt::AlignCenter);
    maxT->setReadOnly(true);
    tableWidget->setCellWidget(7,4,maxT);

    minT = new QTextEdit("Minimo:");
    minT->setAutoFillBackground(true);
    minT->setAlignment(Qt::AlignCenter);
    minT->setReadOnly(true);
    tableWidget->setCellWidget(7,6,minT);

    mediaT = new QTextEdit("Media:");
    mediaT->setAutoFillBackground(true);
    mediaT->setAlignment(Qt::AlignCenter);
    mediaT->setReadOnly(true);
    tableWidget->setCellWidget(7,8,mediaT);

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
