#include <iostream>

using namespace std;
int main(int argc, char *argv[]) {
	int n;
	char a,b;
	int firstFlag;
	char buf[80][80];
	
	while(1){
		cin>>n>>a>>b;
		firstFlag=true;
		for(int i=0;i<80;i++)
		{
			for(int j=0;j<80;j++)
				buf[i][j]=' ';
		}
		if(firstFlag==false)
		{
			cout<<endl;
		}
		for(int j=1;j<=n;j=j+2)
		{
			if(j/2%2==1)
			{
				for(int k=0;k<j;k++)
				{
					buf[n/2+1-j][n/2+1-j+k]=a;
					buf[n/2+1-j+k][n/2+1-j]=a;
					buf[n/2+1-j+k][n/2+1]=a;
					buf[n/2+1][n/2+1-j+k]=a;
				}
			}
			else{
				for(int k=0;k<j;k++){
					buf[n/2+1-j][n/2+1-j+k]=b;
					buf[n/2+1-j+k][n/2+1-j]=b;
					buf[n/2+1-j+k][n/2+1]=b;
					buf[n/2+1][n/2+1-j+k]=b;
				}
			}
			
			if(n!=1){
				buf[0][n-1]=' ';
				buf[n-1][0]=' ';
				buf[0][0]=' ';
				buf[n-1][n-1]=' ';
			}
			
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				cout<<buf[i][j];
			cout<<endl;
		}	
	}
}