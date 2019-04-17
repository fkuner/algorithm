#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char *argv[]) {
	char tmp[100];
	gets(tmp);
	for(int i=0;i<100;i++)
	{
		cout<<tmp[i];
	}
}