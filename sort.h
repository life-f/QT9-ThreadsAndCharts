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
    bool running() const;
//    int *getArray() const;

public slots:
    void setRunning(bool running);
    void run();

signals:
    void finished();    // Сигнал, по которому будем завершать поток, после завершения метода run
    void runningChanged(bool running);
};

#endif // SORT_H
