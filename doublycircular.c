/*Q3. Write a C/C++ program to implement doubly circular linked list
with below metioned functionality.
a) insertAtEnd b) insertAtBeg c) insertAtPos
d) display e) listNodeCount f) deleteFromEnd
g) deleteFromBeg h) deleteFromPos
	Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		int data;
		struct node *prev;
		struct node *nxt;	
	}node;
int menu();
int nodecount(node *head);
void deletelastnode(node **head);
void deletebeg(node **head);
void display(node *head);
void insertatend(node **head,int val);
void insertatbeg(node **head,int val);
void insertatpos(node **head,int val,int pos);
void deleteatpos(node **head,int pos);
void check(node *ptr);
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
				case 9:
				flag=0;
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
void insertatbeg(node **head,int val)
{
	node *ptr;
	ptr=*head;
	node *temp=(node *)malloc(sizeof(node));
	check(temp);
	temp->data=val;
	if(NULL==*head){
		temp->prev=temp;
		temp->nxt=temp;
		*head=temp;
		return;
	}
	while(ptr->nxt!=(*head)){
		ptr=ptr->nxt;
	}
	temp->prev=ptr;
	ptr->nxt=temp;
	temp->nxt=(*head);
	(*head)->prev=temp;
	(*head)=temp;
}
void insertatend(node **head,int val)
{
	node *ptr=(*head);
	node *temp=(node *)malloc(sizeof(node));
	check(temp);
	temp->data=val;
	if(NULL==*head){
		temp->prev=temp;;
		temp->nxt=temp;
		*head=temp;
		return;
	}
	while(ptr->nxt!=(*head)){
		ptr=ptr->nxt;
	}
	ptr->nxt=temp;
	temp->prev=ptr;
	temp->nxt=(*head);	
}
void display(node *head)
{
	node *ptr=head;
	if(head==NULL){
	puts("list is empty");
		return;
	}
	do{
		printf("%d ",ptr->data);
		ptr=ptr->nxt;
	}while(ptr!=head);
}
void deletebeg(node **head)
{
	node*ptr=(*head);
	if(*head==NULL){
		puts("List is empty");
		return;
	}
	if(ptr->nxt==*head){
	free(ptr);
	*head=NULL;
	return;
	}
	while(ptr->nxt!=(*head)){
		ptr=ptr->nxt;
	}
	ptr->nxt=(*head)->nxt;
	(*head)->nxt->prev=ptr;
	free(*head);
	(*head)=(*head)->nxt;
}
void deletelastnode(node **head)
{
	node *ptr=(*head);
	if(*head==NULL){
		puts("List is empty");
		return;
	}
	if(ptr->nxt==*head){
	free(ptr);
	*head=NULL;
	return;
	}
	while(ptr->nxt!=(*head)){
		ptr=ptr->nxt;
	}
	ptr->prev->nxt=(*head);
	(*head)->prev=ptr->prev;
	free(ptr);
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
void check(node *ptr)
{
	if(NULL==ptr){
		puts("not able to allocate");
	}
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
	if(pos>nodecount(*head)+1){
	puts("desired position does not exist");
	return;
	}
	ptr=*head;
	while((i<pos-1)&&ptr->nxt!=(*head)){
					ptr=ptr->nxt;
					i++;
				}
	if(ptr->nxt==(*head)){
	insertatend(head,val);
	return;
	}
	temp->nxt=ptr->nxt;
	temp->prev=ptr;
	ptr->nxt=temp;
}
void deleteatpos(node **head,int pos)
{
	node *ptr=(*head);
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
			ptr=ptr->nxt;
			i++;
		}
	if(ptr->nxt==*head){
	deletelastnode(head);
	return;
	}
	ptr->prev->nxt=ptr->nxt;
	free(ptr);
}
