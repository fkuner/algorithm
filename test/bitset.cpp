#include <iostream>
#include <bitset>
using namespace std;
string s1="A1A2A3A4";
string s2="B1B2B3B4";
int convertToNumber(char c);
char convertToChar(int a);
char a[16][4]={
    0000,
    0001,
    0010,
    0011,
    0100,
    0101,
    0110,
    0111,
    1000,
    1001,
    1010,
    1011,
    1100,
    1101,
    1110,
    1111
};
int main()
{
    // string s;
    // s="1100";
    // s+="0011";
    // bitset<8> bitvec(s);
    // cout<<bitvec<<endl;
    // return 1;
    
    return 1;
}
void method1()
{
    string tmp;
    int tmp1,tmp2,tmp3;
    for(int i=0;i<8;i++)
    {
        tmp1=convertToNumber(s1[i]);
        tmp2=convertToNumber(s2[i]);
        tmp3=tmp1^tmp2;
        tmp+=convertToChar(tmp3);
    }
    cout<<tmp<<endl;
}
void method2()
{
    string tmp1,tmp2;
    bitset<32> bt1;
    bitset<32> bt2;
}
int convertToNumber(char c)
{
    if(c>='0'&&c<='9')
        return c-'0';
    else if(c>='a' && c<='f')
        return c-'a'+10;
    else
        return c-'A'+10;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                      
}
char convertToChar(int a)
{
    if(a<10)
        return a+'0';
    else
        return a+'A'-10;
}
