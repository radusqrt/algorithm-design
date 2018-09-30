#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
struct Node {
  int info;
  Node * next;
} *start, *ptr, *newptr, *save, *rear;
Node * NewNode(int);
void Insert(Node *);
void Traverse(Node* );
int main(){
  start=rear=NULL;
  int inf;
  char ch='Y';
  while(ch=='Y'||ch=='y'){
    cout<<"Enter the information in new node\n";
    cin>>inf;
    newptr=NewNode(inf);
    if(newptr==NULL) {
      cout<<"Can not create node\n";
      exit(1);
     }
     Insert(newptr);
     cout<<"The list is\n";
    Traverse(start);
     cout<<"Press Y to enter more node else any key to exit\n";
     cin>>ch;
  }
  return 0;
}
 Node * NewNode(int n) {
  ptr=new Node;
  ptr->info=n;
  ptr->next=NULL;
  return ptr;
 }
 void Insert(Node * np) {
  if(start==NULL) {
    start=rear=np;
  }
  else {
    rear->next=np;
    rear=np;
  }
 }
 void Traverse(Node *np) {
  while(np!=NULL) {
    cout<<np->info<<"->";
    np=np->next;
  }
  cout<<"\n";
}
