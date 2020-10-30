#ifndef FILEDICALCOLO_WINDOW_H
#define FILEDICALCOLO_WINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QTableWidget>
#include <QString>
#include "Sum.h"
#include "Max.h"
#include "Min.h"
#include "Media.h"
#include "Cells.h"

class Window: public QMainWindow {
    Q_OBJECT

public:
    Window(QWidget *parent);
    list<Cells*> getCells() {return c;}
signals:
    void changeValues(int row, int column, double s);

public slots:
    void cellChanged (int row, int column);
private:
    QTableWidget* tableWidget;
    QTextEdit* sumT;
    QTextEdit* maxT;
    QTextEdit* minT;
    QTextEdit* mediaT;
    Sum* sum;
    Max* max;
    Min* min;
    Media* media;
    QTextEdit* sumCell;
    QTextEdit* maxCell;
    QTextEdit* minCell;
    QTextEdit* mediaCell;
    list<Cells*> c;
    list<Cells*> cc;
};

#endif //FILEDICALCOLO_WINDOW_H
