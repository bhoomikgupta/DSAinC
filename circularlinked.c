/*Q1. Write a C/C++ program to implement single circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos
	Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		int data;
		struct node *nxt;	
	}node;
int menu();
int nodecount(node *head);
void display(node *head);
void deletelastnode(node ** head);
void insertatbeg(node **head,int val);
void deletelastnode(node ** head);
void deletebeg(node **head);
void insertatend(node **head,int data);
void insertatpos(node **head,int val,int pos);
void deleteatpos(node **head,int pos);
int main()
{
	int ch;
	int flag=1;
	int val;
	int pos;
	node *head=NULL;
	while(flag){
			ch=menu();
			switch(ch){
				case 1:
				puts("Enter the value");
				scanf("%d",&val);
				insertatend(&head,val);
				break;
				case 2:
				puts("Enter the value");
				scanf("%d",&val);
				insertatbeg(&head,val);
				break;
				case 3:
				puts("Enter the position");
				scanf("%d",&pos);
				puts("Enter the value");
				scanf("%d",&val);
				insertatpos(&head,val,pos);
				break;
				case 4:
				display(head);
				break;
				case 5:
				val=nodecount(head);
				printf("count=%d",val);
				break;
				case 6:
				deletelastnode(&head);
				break;
				case 7:
				deletebeg(&head);
				break;
				case 8:
				puts("Enter the position");
				scanf("%d",&pos);
				deleteatpos(&head,pos);
				break;
				default:
				puts("wrong input is given");
				break;
				}
			
			}

}
int menu()
{
	int ch;
	puts("Doubly linked list\n1. insert at end\n2. insert at beg\n3. insert at pos\n4. display\n5. list node count\n6. delete from end\n7. delete from beg\n8. delete from position\n9.exit");
	scanf("%d",&ch);
	return ch;
}
int nodecount(node *head)
{
	node *ptr=head;
	int count=0;
	if(head==NULL){
		return 0;
	}
	do{
		ptr=ptr->nxt;
		count++;
	}while(ptr!=head);
	return count;
}
void display(node *head)
{
	node *ptr=(head);
	if(head==NULL){
		return;
	}
	do{
		printf("%d ",ptr->data);
		ptr=ptr->nxt;
	}while(ptr!=head);
}
void insertatend(node **head,int data)
{
	node *ptr=(*head);
	node *temp=(node *)malloc(sizeof(node));
	if(temp==NULL){
		printf("Not able of allovate");
		return;
	}
	temp->data=data;
	if(*head==NULL){
		temp->nxt=temp;
		*head=temp;
		return ;
	}
	while(ptr->nxt!=*head){
		ptr=ptr->nxt;
	}
	ptr->nxt=temp;
	temp->nxt=*head;
	
}
void insertatbeg(node **head,int val)
{
	node *ptr=*head;
	node *temp=(node *)malloc(sizeof(node));
	if(temp==NULL){
		printf("not able to allocate");
		return ;
	}
	temp->data=val;
	if(*head==NULL){
		*head=temp;
		temp->nxt=temp;
		return ;
	}
	while(ptr->nxt!=*head){
		ptr=ptr->nxt;
	}
	temp->nxt=*head;
	ptr->nxt=temp;
	*head=temp;
	return;
}
void deletelastnode(node ** head)
{
	node *ptr=*head;
	node *preptr=NULL;
	if(*head==NULL){
		puts("list is empty");
		return ;
	}
	if(ptr->nxt==*head){
	free(ptr);
	*head=NULL;
	return;
	}
	while(ptr->nxt!=*head){
		preptr=ptr;
		ptr=ptr->nxt;
	}
	preptr->nxt=ptr->nxt;
	free(ptr);
	return ;
}
void deletebeg(node **head)
{
	node *ptr=(*head);
	node *preptr=NULL;
	if(*head==NULL){
		puts("linked list is empty");
		return ;
	}
	if(ptr->nxt==*head){
	free(ptr);
	*head=NULL;
	return;
	}
	while(ptr->nxt!=*head){
		ptr=ptr->nxt;
	}
	ptr->nxt=(*head)->nxt;
	(*head)=(*head)->nxt;
	free(preptr);
	return ;
}
void insertatpos(node **head,int val,int pos)
{
	int i=1;
	node *ptr;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(temp==NULL){
		printf("not able to allocate");
		return ;
	}
	temp->data=val;
	if(pos==1){
	insertatbeg(head,val);
	return ;
	}
	ptr=*head;
	if(pos>nodecount(*head)){
	puts("desired position does not exist");
	return;
	}
	while((i<pos-1)&&ptr->nxt!=(*head)){
					ptr=ptr->nxt;
					i++;
				}
	if(ptr->nxt==*head){
	insertatend(head,val);
	return;
	}
	temp->data=val;
	temp->nxt=ptr->nxt;
	ptr->nxt=temp;
}
void deleteatpos(node **head,int pos)
{
	node *ptr=(*head);
	node *preptr;
	int i=1;
	if(*head==NULL){
		puts("list is empty");
		return;
		}
	if(pos==1){
		deletebeg(head);
		return;
	}
	if(pos>nodecount(*head)){
	puts("desired position does not exist");
	return;
	}
	while((i<pos)&&(ptr->nxt!=*head)){
			preptr=ptr;
			ptr=ptr->nxt;
			i++;
		}
	if(ptr->nxt==*head){
	deletelastnode(head);
	return;
	}
	preptr->nxt=ptr->nxt;
	free(ptr);
}
