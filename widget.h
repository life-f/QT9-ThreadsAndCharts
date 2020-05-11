#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QThread>
#include "sort.h"

#include <QChart>
#include <QBarSeries>
#include <QBarSet>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

using namespace QtCharts;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    QThread *thread;
    Sort* array;
    QChart *graph;

private:
    void createGraph();
    QBarSeries* createSeries();

private slots:
    void startClicked();
    void stopClicked();
};
#endif // WIDGET_H
