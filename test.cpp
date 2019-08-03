#include <iostream>  
#include <algorithm>  
#include <set>
using namespace std;  
int main()  
{  
    int num[3]={1,2,3};  
    do  
    {  
        cout<<num[0]<<" "<<num[1]<<" "<<num[2]<<endl;  
    }while(next_permutation(num,num+3));

    cout<<endl;
    set<int> st;
    st.insert(1);
    st.insert(1);
    cout<<st.size();
    cout<<endl;
    return 0;  
}