#ifndef LINKEDLIST_H
#define LINKEDLIST_H
struct node {
	struct node* next;
	int data;
};

struct node* head=NULL, *temp=NULL, *newn;

void printll();
#endif
