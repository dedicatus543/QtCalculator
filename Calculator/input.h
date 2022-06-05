#ifndef INPUT_H
#define INPUT_H

#include <QObject>
#include<stack>
#include<string>
#include<cmath>
#define N 9999
class Input : public QObject
{
    Q_OBJECT
    std::string suffixExp[N];
    std::string operators = "()+-*/^";
    size_t exp_length;
public:
    explicit Input(QObject *parent = nullptr);
    void convert(std::string src);
    double calculate();
signals:

};

#endif // INPUT_H
