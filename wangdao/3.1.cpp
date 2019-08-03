
#include <iostream>
#include <stack>
using namespace std;
int main()
{
    char str[101];
    char ans[101];
    while(scanf("%s",str)!=EOF)
    {
        stack<char> st;
        int i;
        for(i=0;str[i]!=0;i++)
        {
            if(str[i]=='(')
            {
                st.push(i);
                ans[i]=' ';
            }
            else if(str[i]==')')
            {
                if(st.empty())
                    ans[i]='?';
                else
                {
                    ans[i]=' ';
                    st.pop();
                }    
            }
            else
                ans[i]=' ';
        }
        while(!st.empty())
        {
            ans[st.top()]='$';
            st.pop();
        }
        ans[i]=0;
        puts(str);
        puts(ans);
    }
}