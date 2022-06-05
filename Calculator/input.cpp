#include "input.h"
#include <QDebug>
//输入 -9 3-----2这样的需要在更前一步确认，而微软计算器将-9 视为 0-9， 运算符位置只能输入一个
//用户输入
Input::Input(QObject *parent) : QObject(parent)
{

}
void Input::convert(std::string src){
    size_t length = src.length();
    bool split[length+1];
    std::stack<std::string> tmpstack;
    //将中缀表达式转换成后缀表达式
    for(size_t i =0;i<length;i++){
        if((src[i] >= '0' && src[i] <= '9') || src[i]=='.'){//需要注意子字符串可能有多于一个的小数点
            split[i] = 1;                                   //在转换时要注意提前排查
        }
        else split[i] = 0;//将原始表达式的数字 与 运算符或函数 通过bool数组分隔
    }
    exp_length = 0;
    for(size_t i =0;i<length;){
        if(split[i]){
            size_t sublen = 1;
            while(i+sublen < length && split[i+sublen]){
                sublen += 1;
            }//获取数字的子字符串及长度
            if(exp_length < N)
                suffixExp[exp_length++] = src.substr(i,sublen);//将子字符串直接添加后缀表达式
            i += sublen;
        }

        else{
            size_t sublen = 1;
            while(i+sublen < length && !split[i+sublen]){
                sublen += 1;
            }//获取非数字的子字符串及长度
            std::string temp = src.substr(i,sublen);
            if(temp == "("){
                tmpstack.push(temp);
            }
            else if (temp ==")") {
                while(tmpstack.top() != "(" && exp_length<N){
                    suffixExp[exp_length++] = tmpstack.top();
                    tmpstack.pop();
                }
                tmpstack.pop(); // 弹出左括号但不输出
            }
            else if (operators.find(temp) != std::string::npos) {
                while(exp_length<N && !tmpstack.empty() && (operators.find(temp) <= operators.find(tmpstack.top()))){
                    suffixExp[exp_length++] = tmpstack.top();
                    tmpstack.pop();
                }
                tmpstack.push(temp);
            }
            i += sublen;
                            //通过栈结构控制运算符优先级
        }
    }
    while(!tmpstack.empty()){
        suffixExp[exp_length++] = tmpstack.top();
        tmpstack.pop();
    }
}
double Input::calculate(){
    std::stack<double> oper_stack;
    for(size_t i = 0; i<exp_length; i++){
        long double num = 0;
        if(sscanf(suffixExp[i].c_str(), "%Lf", &num) == 1){
           oper_stack.push(num);
        }
        else{
            double d1 = oper_stack.top();
            oper_stack.pop();
            double d2 = oper_stack.top();
            oper_stack.pop();
            if(suffixExp[i] == "+"){
                oper_stack.push(d2+d1);
            }
            else if(suffixExp[i] == "-"){
                oper_stack.push(d2-d1);
            }
            else if(suffixExp[i] == "*"){
                oper_stack.push(d2*d1);

            }
            else if(suffixExp[i] == "/"){
                oper_stack.push(d2/d1);
            }
            else if(suffixExp[i] == "^"){
                oper_stack.push(powl(d1,d2));
            }
        }
    }
    return oper_stack.top();
}
