#include "widget.h"
#include "ui_widget.h"
#include <random>
#include <QChartView>
#include <QDebug>
#include <QBarCategoryAxis>
#include <QValueAxis>

Widget::Widget(QWidget *parent)
    : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);

    thread = new QThread();
    array = new Sort(50 /*0000*/);
//    array->moveToThread(thread);
//    generateArray();
//    graph = new QChart();
//    createGraph();


    connect(ui->start, &QPushButton::clicked, this, &Widget::startClicked);
    connect(ui->stop, &QPushButton::clicked, this, &Widget::stopClicked);
    connect(thread, &QThread::started, array, &Sort::run);
    connect(array, &Sort::finished, thread, &QThread::terminate);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::createGraph()
{
//    QBarSeries *series = createSeries();
//    graph->addSeries(series);
//    graph->setAnimationOptions(QChart::SeriesAnimations);
//    QBarCategoryAxis *axisX = new QBarCategoryAxis();
//    axisX->append(categories);
//    graph->addAxis(axisX, Qt::AlignBottom);
//    series->attachAxis(axisX);

//    QValueAxis *axisY = new QValueAxis();
//    axisY->setRange(0,15);
//    graph->addAxis(axisY, Qt::AlignLeft);
//    series->attachAxis(axisY);
//    QChartView *view = new QChartView(/*ui->widget*/graph);
//    view->setRenderHint(QPainter::Antialiasing);
//    view->setChart(graph);
}

QBarSeries* Widget::createSeries()
{
//    QBarSet *set = new QBarSet("data");
//    for (int i=0; i<n; i++) {
//        *set << array[i];
//    }
//    QBarSeries *series = new QBarSeries();
//    series->append(set);
//    return series;
}

void Widget::startClicked()
{
    array->moveToThread(thread);
    array->setRunning(true);
    thread->start();
}

void Widget::stopClicked()
{
    array->setRunning(false);
//    thread->exit();
}

