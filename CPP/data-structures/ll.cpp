#include <iostream>
#include "LinkedList.h"

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
