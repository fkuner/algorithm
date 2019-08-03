#include <iostream>
#include <vector>
using namespace std;

template<class T>
int count(vector<T> a ,T value);
int abc(int a,int b,int c);
template<class T>
bool make2dArray(T ** &x,int numberOfRows, int *rowSize);
int main()
{
    vector<int> b(5,1);
    cout<<count(b,1)<<endl;
    
    //exception
    // try
    // {
    //     cout<<abc(-1,-2,-3);
    // }
    // catch(char* e)
    // {
    //     cout<<"haha"<<endl;
    //     cout<<e<<endl;
    // }

    //1-12
    int a[5]={1,2,3,4,5};
    int **x;
    cout<<make2dArray(x,5,a)<<endl;

    //
    return 0;


}
template<class T>
int count(vector<T> a ,T value)
{
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]==value)
            cnt++;
    }
    return cnt;
}
int abc(int a,int b,int c)
{
    if(a<0 && b<0 && c<0)
        throw "haha";
    else if(a==0 && b==0 &&c==0)
        throw 2;
    else
        return a+b+c;
}
template <class T>
bool make2dArray(T ** &x,int numberOfRows, int *rowSize)
{
    try{
        x=new T * [numberOfRows];
        for(int i=0;i<numberOfRows;i++)
        {
            x[i]=new T[rowSize[i]];
            return true;
        }
    }catch(bad_alloc)
    {
        return false;
    }
}
