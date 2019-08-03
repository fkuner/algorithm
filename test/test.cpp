#include <iostream>
using namespace std;
char getc(char c);
int main()
{
    char c;
    while(1)
    {
        c=getchar();
        cout<<getc(c)<<endl;
    }
    return 1;
}
char getc(char c){
	if(c<10)
		return c+'0';
	else if(c<=16)
		return c+'A'-10;
	else if(c<='9')
		return c-'0';
	else if(c<='F')
		return c-'A'+10;
    return 0;
}
