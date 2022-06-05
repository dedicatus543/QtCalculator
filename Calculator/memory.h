#ifndef MEMORY_H
#define MEMORY_H

#include <QObject>

class Memory : public QObject
{
    Q_OBJECT
public:
    explicit Memory(QObject *parent = nullptr);

signals:

};

#endif // MEMORY_H
