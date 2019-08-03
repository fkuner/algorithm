/* Kun 重做
没有考虑多位数数字问题
没有考虑空格
入栈逻辑混乱
#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
int mat[5][5]={
    1,0,0,0,0,
    1,0,0,0,0,
    1,0,0,0,0,
    1,1,1,0,0,
    1,1,1,0,0
}; //保存优先级关系
bool isNumber(char c);
double cal(int a,double nm1,double nm2);
int convertToInt(char c);
int main()
{
    char str[201]; //保存表达式字符串
    while(scanf("%s",str)!=EOF)
    {
        stack<int> op;
        stack<double> nm;
        for(int i=0;i<201;i++)
        {
            //首先压入标志符
            if(i==0)
                op.push(0);
            //将数字直接压入存放数字栈
            if(isNumber(str[i]))
                nm.push(str[i]-'0');  
            else
            {
                if(op.empty())
                    op.push(convertToInt(str[i]));  //操作符栈为空，直接压入
                else
                {
                    //判断字符串是否结束
                    char c;
                    int temp=op.top();
                    //如果运算符栈顶运算符优先级小于该运算符
                    if(mat[convertToInt(str[i])][temp]==1)
                    {
                        op.push(convertToInt(str[i]));
                    }
                    //如果运算符栈顶运算符优先级大于等于该运算符
                    else
                    {
                        int temp=op.top();
                        op.pop();
                        double number1 = nm.top();
                        nm.pop();
                        double number2 = nm.top();
                        nm.pop(); 
                        double number3 = cal(temp,number1,number2);
                        nm.push(number3);
                        //继续比较当前运算符与栈顶运算符优先级
                        i--;
                    }
                }
            }
            //判断是否运算符堆栈中仅存有两个运算符且栈顶元素为0
            if(!op.empty()&&op.top()==0&&op.size()==2)
            {
                cout<<nm.top();
                break; 
            }
        }
    }
    return 1;
}
bool isNumber(char c)
{
    if(c>='0'&&c<='9')   
        return true;
}
double cal(int a,double nm1,double nm2)
{
    if(a==1)
        return nm1+nm2;
    else if(a==2)
        return nm1-nm2;
    else if (a==3)
        return nm1*nm2;
    else
        return nm1/nm2;
}
int convertToInt(char c)
{
    if(c=='+')
        return 1;
    else if(c=='-')
        return 2;
    else if (c=='*')
        return 3;
    else if (c=='/')
        return 4;
    else
        return 0;
}
*/