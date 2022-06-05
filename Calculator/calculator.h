#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <QMainWindow>
#include"input.h"
#include"function.h"
#include"memory.h"
#include<QDebug>
QT_BEGIN_NAMESPACE
namespace Ui { class Calculator; }
QT_END_NAMESPACE

class Calculator : public QMainWindow
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    ~Calculator();
    double calculate();
private slots:
    void expAppendZero();
    void expAppendOne();
    void expAppendTwo();
    void expAppendThree();
    void expAppendFour();
    void expAppendFive();
    void expAppendSix();
    void expAppendSeven();
    void expAppendEight();
    void expAppendNine();
    void expAppendAdd();
    void expAppendMinus();
    void expAppendMulti();
    void expAppendDivide();
    void expAppendEqual();
    void expAppendPow();
    void expAppendPoint();
private:
    Ui::Calculator *ui;
    std::string cur_buffer;
    std::string cal_buffer;
    std::string show_buffer;
    Input input;
    bool first;//第一个输入的数字不能是0
    bool point;//控制小数点不多于1

};
#endif // CALCULATOR_H
