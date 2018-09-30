struct node {
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
