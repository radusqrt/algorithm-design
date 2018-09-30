/*Stack Implementation using Arrays in C++
  created by DarkSun27*/

#include <iostream>
#define size 100
using namespace std;

int arr[size],tos=0;
void push(int value)
{
	if(tos==size)
	{
		cout<<"Size of stack is full";
		return;
	}
	arr[tos++]=value;
}
int pop()
{
	if(tos!=0)
	{
		return arr[--tos];
	}
	cout<<"Empty Stack";
	return -1;
}
int main(){
	int t; //defines number of times user wants to test stack
	cin>>t;
	for(int i=0;i<t;i++){
		int opt=0;
		cin>>opt;     // 1 for push and 2 for pop
		switch(opt)
		{
			case 1:int value;cin>>value;push(value);break;
			case 2:cout<<pop();break;
			default:cout<<"Wrong Option";break;
		}
	}
	return 0;
}
