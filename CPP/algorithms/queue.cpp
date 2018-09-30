/*Queue Implementation using Arrays in C++
  created by DarkSun27*/

#include <iostream>
#define size 100

using namespace std;

int arr[size],front=0,rear=0;

void enque(int value)
{
	if(rear==size)
	{
		cout<<"Size of queue is full";
		return;
	}
	arr[rear++]=value;
}

int deque()
{
	if(front<rear)
	{
		return arr[front++];
	}
	cout<<"Empty Queue";
	return -1;
}

int main(){
	int t; //defines number of times user wants to test queue
	cin>>t;
	for(int i=0;i<t;i++){
		int opt=0;
		cin>>opt;     // 1 for enque and 2 fr deque
		switch(opt)
		{
			case 1:int value;cin>>value;enque(value);break;
			case 2:cout<<deque;break;
			default:cout<<"Wrong Option";break;
		}
	}
	return 0;
}
