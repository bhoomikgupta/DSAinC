/*Q2. Write a C/C++ program to implement doubly linked list with below
metioned functions functionality.
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
void deleteatpos(node **head,int pos);
void display(node *head);
void insertatpos(node **head,int val,int pos);
int nodecount(node *head);
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
				insertatpos(&head,val,nodecount(head)+1);
				break;
				case 2:
				puts("Enter the value");
				scanf("%d",&val);
				insertatpos(&head,val,1);
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
				deleteatpos(&head,nodecount(head));
				break;
				case 7:
				deleteatpos(&head,1);
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
void insertatpos(node **head,int val,int pos)
{
	int i=1;
	node *ptr=*head;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	if(!temp){
		puts("Not able to allocate");
		return;		
		}
	else{
			temp->data=val;
			if(pos==1){	//inserting at beginning node
					temp->nxt=*head;
					temp->prev=NULL;
					if(*head){
							(*head)->prev=temp;
						}
					*head=temp;
					return;
				}
			while((i<pos-1)&&ptr->nxt!=NULL){
					ptr=ptr->nxt;
					i++;
				}
				if(i!=(pos-1)){
						puts("desired position does not exist");
						return;
					}
				temp->nxt=ptr->nxt;
				temp->prev=ptr;
			if(ptr->nxt){
			ptr->nxt->prev=temp;
			}
			ptr->nxt=temp;
			return;
		}
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
	if(pos==1){	//deleting at starting node
		(*head)=(*head)->nxt;
		if(*head!=NULL)
		(*head)->prev=NULL;
		free(ptr);
		return ;
		}
	while((i<=pos)&&(ptr->nxt!=NULL)){
			ptr=ptr->nxt;
			i++;
		}
	if(i!=pos){
		puts("desired position does not exist\n");
		return;
		}
	
	preptr=ptr->prev;
	preptr->nxt=ptr->nxt;
	if(ptr->nxt){
		ptr->nxt->prev=preptr;
		}
		free(ptr);
		return ;
}
void display(node *head)
{
	node *ptr;
	ptr=head;
	while(ptr!=NULL){
		printf("%d ",ptr->data);
		ptr=ptr->nxt;
		}
}
int nodecount(node *head)
{
	int count=0;
	node *ptr=head;
	while(ptr!=NULL){
		ptr=ptr->nxt;
		count++;
	}
	return count;
}
