#include <iostream>
#include <LnkedList.h>

using namespace std;

int main()
{
	int opt;
	cout<<"1 for inserting 2 for printing";
	cin>>opt;
	switch(opt)
	{
		case 1:
			while(opt==1)
			{
				int data;
				cin>>data;
				newn = (struct node*)malloc(sizeof(struct node));
				newn->data=data;
				if(head!=NULL)
				{
					temp->next=newn;
					temp=newn;
					temp->next=NULL;
				}
				else{
					head=temp=newn;
					temp->next=NULL;
				}
				cin>>opt;
			}
			if(opt==2)
			{
				printll();
			}
			break;
		case 2:
		printll();
		break;
	}
	return 0;
}
