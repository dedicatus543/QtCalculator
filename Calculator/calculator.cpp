#include "calculator.h"
#include "ui_calculator.h"

Calculator::Calculator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Calculator)
{
    first = false;//确保首位数字非零
    point = true;//小数点不多于一个

    ui->setupUi(this);
    input.setParent(this);

    ui->output_label->setAlignment(Qt::AlignRight);
    ui->history_label->setAlignment(Qt::AlignRight);

    connect(ui->actionExit, &QAction::triggered, this, &Calculator::close);
    connect(ui->input_0, &QPushButton::pressed, this, &Calculator::expAppendZero);
    connect(ui->input_1, &QPushButton::pressed, this, &Calculator::expAppendOne);
    connect(ui->input_2, &QPushButton::pressed, this, &Calculator::expAppendTwo);
    connect(ui->input_3, &QPushButton::pressed, this, &Calculator::expAppendThree);
    connect(ui->input_4, &QPushButton::pressed, this, &Calculator::expAppendFour);
    connect(ui->input_5, &QPushButton::pressed, this, &Calculator::expAppendFive);
    connect(ui->input_6, &QPushButton::pressed, this, &Calculator::expAppendSix);
    connect(ui->input_7, &QPushButton::pressed, this, &Calculator::expAppendSeven);
    connect(ui->input_8, &QPushButton::pressed, this, &Calculator::expAppendEight);
    connect(ui->input_9, &QPushButton::pressed, this, &Calculator::expAppendNine);
    connect(ui->input_add, &QPushButton::pressed, this, &Calculator::expAppendAdd);
    connect(ui->input_minus, &QPushButton::pressed, this, &Calculator::expAppendMinus);
    connect(ui->input_divide, &QPushButton::pressed, this, &Calculator::expAppendDivide);
    connect(ui->input_multiply, &QPushButton::pressed, this, &Calculator::expAppendMulti);
    connect(ui->input_equal, &QPushButton::pressed, this, &Calculator::expAppendEqual);
    connect(ui->input_power, &QPushButton::pressed, this, &Calculator::expAppendPow);
    connect(ui->input_point, &QPushButton::pressed, this, &Calculator::expAppendPoint);

}

Calculator::~Calculator()
{
    delete ui;
}

void Calculator::expAppendZero()
{
    if(first){
        cur_buffer.append("0");
        qDebug()<<"expAppendZero";
        ui->output_label->setText(QString::fromStdString(cur_buffer));
    }
}
void Calculator::expAppendOne(){
    cur_buffer.append("1");
    qDebug()<<"expAppendOne";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendTwo(){
    cur_buffer.append("2");
    qDebug()<<"expAppendTwo";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendThree(){
    cur_buffer.append("3");
    qDebug()<<"expAppendThree";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendFour(){
    cur_buffer.append("4");
    qDebug()<<"expAppendFour";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendFive(){
    cur_buffer.append("5");
    qDebug()<<"expAppendFive";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendSix(){
    cur_buffer.append("6");
    qDebug()<<"expAppendSix";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendSeven(){
    cur_buffer.append("7");
    qDebug()<<"expAppendSeven";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendEight(){
    cur_buffer.append("8");
    qDebug()<<"expAppendEight";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}

void Calculator::expAppendNine(){
    cur_buffer.append("9");
    qDebug()<<"expAppendNine";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    first = true;
}
void Calculator::expAppendAdd(){
    if(cur_buffer.empty())
        cur_buffer.append("0");
    cal_buffer.append(cur_buffer + "+");
    cur_buffer.clear();
    qDebug()<<"expAppendAdd";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    show_buffer = cal_buffer;
    ui->history_label->setText(QString::fromStdString(show_buffer));
    first = false;

}
void Calculator::expAppendMinus(){
    if(cur_buffer.empty()){
        cur_buffer.append("0");
    }
    cal_buffer.append(cur_buffer + "-");
    cur_buffer.clear();
    qDebug()<<"expAppendAdd";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    show_buffer = cal_buffer;
    ui->history_label->setText(QString::fromStdString(show_buffer));
    first = false;
}
void Calculator::expAppendMulti(){
    if(cur_buffer.empty()){
        cur_buffer.append("0");
    }
    cal_buffer.append(cur_buffer + "*");
    cur_buffer.clear();
    qDebug()<<"expAppendAdd";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    show_buffer = cal_buffer;
    ui->history_label->setText(QString::fromStdString(show_buffer));
    first = false;
}
void Calculator::expAppendDivide(){
    if(cur_buffer.empty()){
        cur_buffer.append("0");
    }
    cal_buffer.append(cur_buffer + "/");
    cur_buffer.clear();
    qDebug()<<"expAppendAdd";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    show_buffer = cal_buffer;
    ui->history_label->setText(QString::fromStdString(show_buffer));
    first = false;
}
void Calculator::expAppendPow(){
    if(!cur_buffer.empty()){
        cur_buffer.append("0");
    }
    cal_buffer.append(cur_buffer + "^");
    cur_buffer.clear();
    qDebug()<<"expAppendAdd";
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    show_buffer = cal_buffer;
    ui->history_label->setText(QString::fromStdString(show_buffer));
    first = false;
}
void Calculator::expAppendPoint(){
    if(first && point){
        cur_buffer.append(".");
        qDebug()<<"expAppendPow";
        ui->output_label->setText(QString::fromStdString(cur_buffer));
        point = false;
    }
}
void Calculator::expAppendEqual(){
    cal_buffer.append(cur_buffer);
    qDebug()<<"expAppendEqual1";
    char *temp = new char [400];
    qDebug("answer if %f", calculate());
    sprintf(temp, "%.12g", calculate());
    cur_buffer = temp;
    qDebug()<<QString::fromStdString(cur_buffer);
    ui->output_label->setText(QString::fromStdString(cur_buffer));
    delete [] temp;
    show_buffer = cal_buffer;
    show_buffer.append("=");
    ui->history_label->setText(QString::fromStdString(show_buffer));
    show_buffer.clear();
    cal_buffer.clear();
    first = false;
}

double Calculator::calculate(){
    qDebug()<<cal_buffer.c_str();
    input.convert(cal_buffer);
    return input.calculate();
}
