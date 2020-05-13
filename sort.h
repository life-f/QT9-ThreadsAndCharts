/**
  * @file sort.h
  * @brief bubble sort
  * @author Bagrova Polina
  */
#ifndef SORT_H
#define SORT_H

#include <QObject>

class Sort : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)

private:
    bool m_running;
    int *array;
    int n;

public:
    explicit Sort(int qty, QObject *parent = nullptr);
    ~Sort();
    bool running() const;
    int *getArray() const;
    int getN() const;

public slots:
    void setRunning(bool running);
    void run();

signals:
    void finished();
    void runningChanged(bool running);
};

#endif // SORT_H
