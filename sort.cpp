#include "sort.h"
#include <QRandomGenerator>
//#include <QDebug>

Sort::Sort(int qty, QObject *parent) : QObject(parent)
{
    n = qty;
    array = new int(n);
    QRandomGenerator random;
    for(int i=0; i<n; i++)
        array[i] = random.bounded(1,1000);
}

bool Sort::running() const
{
    return m_running;
}

void Sort::setRunning(bool running)
{
    if (m_running == running)
            return;
    m_running = running;
    emit runningChanged(running);
}

void Sort::run()
{
    while (m_running){
        int buf;
        for (int i=0; i<n-1; i++){
            for (int j=0; j<n-i-1;j++){
                if (array[j]>array[j+1]){
                    buf=array[j];
                    array[j]=array[j+1];
                    array[j+1]=buf;
                }
                if(m_running == false)
                    return;
            }
        }
    }
    emit finished();
}

//int *Sort::getArray() const
//{
//    return array;
//}
