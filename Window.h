#ifndef FILEDICALCOLO_WINDOW_H
#define FILEDICALCOLO_WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTableWidget>
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Media.h"
#include "Cells.h"

class Window: public QMainWindow {
    Q_OBJECT

public:
    Window(QWidget *parent);

private slots:
    void cellChanged (int row,  int column);
private:
    QTableWidget* tableWidget;
    QTextEdit* sumT;
    QTextEdit* maxT;
    QTextEdit* minT;
    QTextEdit* mediaT;
    Sum* sum;
    QTextEdit* sumCell;
    Cells* cell;
    
};


#endif //FILEDICALCOLO_WINDOW_H
