/*Q2. Write a C/C++ program to implement single linked list.
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode l) reverseList m)sortedList
	Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
			int data;
			struct node *nxt;			
			}node;
void insertatend(node **ptr,int val);
int menu();
void display(node const*ptr);
void check(node const*p);
void destroy(node *head);
node *search(node const*head,int val);
void modify(node *ptr);
void deletefrompos(node **head,int pos);
void deletefrombeg(node **head);
void insertatbeg(node **head,int val);
void deletefromlast(node **head);
void deletebyelement(node **head,int val);
void insertatpos(node **head,int pos,int val);
void reversedisplay(node const *head);
int listcount(node count*head);
void reverselist(node **head);
void sortedinsert(node **head,int data);
int main()
{
	node *head=NULL;
	node *ptr=NULL;
	int ch;
	int val;
	int pos;
	int flag=1;
	while(flag){
			ch=menu();
			switch(ch){
					case 1:
						printf("enter a number");
						scanf("%d",&val);
						insertatend(&head,val);
						break;
					case 2:
						display(head);
						break;
					case 3:
						flag=0;
						destroy(head);
						break;
					case 4: 
						printf("Enter the value that u want to find");
						scanf("%d",&val);
						ptr=search(head,val);
						if(ptr!=NULL){
								printf("value found in linked list\n");
								ptr=NULL;
								}
						else{
							printf("Not found in linkedlist\n");
							}
						break;
					case 5: printf("Enter the value that u want to modify");
						scanf("%d",&val);
						ptr=search(head,val);
						if(ptr!=NULL){
								printf("value found in linked list\n");
								modify(ptr);
								ptr=NULL;
								}
						else{
							printf("Not found in linkedlist\n");
							}
						break;
					case 6:
						deletefrombeg(&head);
						break;
					case 7:
						deletefromlast(&head);
						break;
					case 8:
						printf("Enter the value");
						scanf("%d",&val);
						insertatbeg(&head,val);
						break;
					case 9:
						printf("Enter the position");
						scanf("%d",&val);
						deletefrompos(&head,val);
						break;
					case 10:
						val=listcount(head);
						printf("total nodes =%d",val);
						break;
					case 11:
						reversedisplay(head);
						break;
					case 12:
						printf("Enter the position");
						scanf("%d",&pos);
						printf("Enter the value");
						scanf("%d",&val);
						insertatpos(&head,pos,val);
						break;
					case 13:
						printf("Enter the value");
						scanf("%d",&val);
						deletebyelement(&head,val);
						break;
					case 14:
						printf("enter the value");
						scanf("%d",&val);
						sortedinsert(&head,val);
						break;
					case 15:
						reverselist(&head);
						break;
					default:
						printf("wrong input given\n");
						break;
					}
				}

}
int menu()
{
	int ch;
	printf("\n\nlinkedlist\n1. Insert a node at end\n2. display list\n3. exit\n4. search an element\n5. modify element\n6. delete from beg\n7. delete from last\n8. insert at beg\n9. delete from position\n10. list count\n11. reverse display\n 12. insert at pos\n13. delete by element\n14. sorted insert\n15. reverse list");
	scanf("%d",&ch);
	return ch;
}
void insertatend(node **ptr,int val)
{
	node *t;
	t=*ptr;
	node *temp=(node *)malloc(sizeof(node));
	check(temp);
	temp->data=val;
	temp->nxt=NULL;
	if(*ptr!=NULL){
			while(t->nxt!=NULL){
						t=t->nxt;
						}
			t->nxt=temp;
			}
	else{
		*ptr=temp;
		}
}
void display(node const*ptr)
{
	while(ptr!=NULL){
				printf("%d-->",ptr->data);
				ptr=ptr->nxt;
				}
	printf("NULL\n");
}
void check(node *p)
{
	if(p==NULL){
			printf("Not able to allocate\n");
			}

}
void destroy(node *head)  
{
     node *temp;         
     while(head!=NULL) 
     {
          temp=head;
          head=head->nxt;
          free(temp);
     }
}
node *search(node const*head,int val)
{
	node *ptr;
	ptr=head;
	while(ptr!=NULL){
				if(ptr->data==val){
							return ptr;
							}
				else{
					ptr=ptr->nxt;
					}
				}
}
void modify(node *ptr)
{
	printf("Enter value\n");
	scanf("%d",&ptr->data);
}
void deletefrombeg(node **head)
{
	if(*head==NULL){
				printf("Linked list is empty\n");
				return ;
				}
	node *ptr;
	ptr=*head;
	*head=ptr->nxt;
	free(ptr);
}
void deletefromlast(node **head)
{
	node *ptr;
	node *preptr;
	ptr=*head;
	if(listcount(*head)==1){
					deletefrombeg(head);
					}
	else{
		while(ptr->nxt!=NULL){
					 preptr=ptr;
					 ptr=ptr->nxt;
		}
		preptr->nxt=NULL;
		free(ptr);
		}
}
void insertatbeg(node **head,int val)
{
	node *temp;
	temp=(struct node*)malloc(sizeof(node));
	check(temp);
	temp->data=val;
	temp->nxt=NULL;
	temp->nxt=*head;
	*head=temp;

}
void deletefrompos(node **head,int pos)
{
	node *temp;
	node *ptr;
	temp=*head;
	int i;
	if(pos<=listcount(*head)){
					if(pos-1==0){
							deletefrombeg(head);
							return ;
							}
					for(i=0;i<pos-1;i++){
								ptr=temp;
								temp=temp->nxt;
								}
					ptr->nxt=temp->nxt;
					free(temp);
					}
	else{
		printf("Deletion cannot be possible");
		}
}
int listcount(node const*head)
{
	int count=0;
	node *ptr;
	ptr=head;
	while(ptr!=NULL){
				ptr=ptr->nxt;
				count++;
				}	
	return count;
}
void reversedisplay(node const*head)
{

	if(head==NULL){
			return;
			}
	reversedisplay(head->nxt);
	printf("%d-->",head->data);
}
void insertatpos(node **head,int pos,int val)
{
	node *ptr;
	node *preptr;
	ptr=*head;
	int i;
	if((pos-1)>listcount(*head)){
					printf("Insertion cannot be possible");
					}
	else{
		if(pos-1==0){
				insertatbeg(head,val);
				}
		else{
			node *temp=(node *)malloc(sizeof(node));
			check(temp);
			temp->data=val;
			for(i=0;i<pos-1;i++){
						preptr=ptr;
						ptr=ptr->nxt;
						}
						preptr->nxt=temp;
						temp->nxt=ptr;
			}
			}

}
void deletebyelement(node **head,int val)
{
	node *ptr;
	node *preptr;
	ptr=*head;
	if(ptr->data==val){
				deletefrombeg(head);	
				return ;
				}
	else{
		while(ptr->data!=val){
					preptr=ptr;
					ptr=ptr->nxt;
					}
		preptr->nxt=ptr->nxt;
		free(ptr);
		}
}
void sortedinsert(node **head,int data)
{
	node *ptr;
	ptr=*head;
	node *preptr;
	node *temp=(node *)malloc(sizeof(node));
	check(temp);
	temp->data=data;
	if(*head!=NULL){
			if(ptr->data > data){
						temp->nxt=ptr;
						*head=temp;
						}
			else{		
				while(ptr->data <= data &&ptr->nxt!=NULL){
											preptr=ptr;
											ptr=ptr->nxt;
											}
					if(ptr->data>data){		
									temp->nxt=ptr;
									preptr->nxt=temp;
										}				
					else{
						ptr->nxt=temp;
						temp->nxt=NULL;
						}
				}
			}
	else if(*head==NULL){
				*head=temp;
				}
			
	
	printf("Succesfully insertion of data\n");
				
}
void reverselist(node **head)
{
	node *ptr;
	node *next=NULL;
	node *preptr=NULL;
	ptr=*head;
	while(ptr!=NULL){
				next=ptr->nxt;
				ptr->nxt=preptr;
				preptr=ptr;
				ptr=next;					
				}
	*head=preptr;
}
node *swap(node*ptr1,node *ptr2)
{
	node *temp=ptr1->nxt;
	ptr1->nxt=ptr2;
	ptr2->nxt=temp;
	return ptr2;	
}
void bubblesort(node **head)
{
	int i;
	int j;
	node *ptr;
	for(i=0;i<=listcount(*head);i++){
						ptr=*head;
						for(j=0;j<listcount(*head)-i-1;j++){
											node *ptr1=ptr;
											node *ptr2=ptr->nxt;
											if(ptr1->data >ptr2->data){
															*ptr=swap(ptr1,ptr2);
															}
											}
						}

}
