#include<iostream>
using namespace std;
struct node{
	struct node* next;
	int data;
};
struct node* head=NULL,*temp=NULL,*newn;
void printll()
{
	if(head==NULL)
	{
		cout<<"Empty List";
		return;
	}
	else{
		temp=head;
		while(temp!=NULL)
		{
			cout<<temp->data<<" ";
			temp=temp->next;
		}
	}
}
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
