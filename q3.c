/*Q3. Write a C/C++ program to implement single linked list in sorted
order. Implement below metioned functions. Apply all required
condition check & validation like list empty or not, while
inserting/deleting by position validate the position. Implement a policy
for duplicate value input.
a)insert b) displayList c)listNodeCount d) deleteFromEnd
e) deleteFromBeg f)deleteFromPos g) reverseDisplay
	Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
		int data;
		struct node *nxt;		
		}node;
void sortedinsert(node **head,int data);
void display(node const*ptr);
void check(node const*p);
int duplicate(node const*head,int val);
void reversedisplay(node const*head);
int listcount(node const*head);
void deletefromlast(node **head);
void deletefrombeg(node **head);
void deletefrompos(node **head,int pos);
int menu();
int main()
{
	int ch;
	int flag=1;
	int val;
	node *head=NULL;
	node *ptr=NULL;
	while(flag){
			ch=menu();
			switch(ch){
			case 1:
				printf("Enter the value");
				scanf("%d",&val);
				sortedinsert(&head,val);
				break;
			case 2:
				display(head);
				break;
			case 3:
				val=listcount(head);
				printf("count=%d",val);
				break;
			case 4:
				deletefrompos(&head,listcount(head));
				printf("Successfully deleted last node\n");
				break;
			case 5:
				deletefrombeg(&head);
				puts("Deleted beginning node\n");
				break;
			case 6:
				printf("Enter the pos");
				scanf("%d",&val);
				deletefrompos(&head,val);
				break;
			case 7:
				reversedisplay(head);
				break;
			default:
				puts("You have entered wrong input\n");
				break;				
				}
			}

}
void sortedinsert(node **head,int data)
{
	node *ptr;
	ptr=*head;
	node *preptr;
	node *temp=(node *)malloc(sizeof(node));
	check(temp);
	if(duplicate(*head,data)==1){
				printf("Duplicacy found in input");
				return ;
					}
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
			
	
	puts("Succesfully insertion of data\n");
				
}
void display(node const*ptr)
{
	while(ptr!=NULL){
				printf("%d-->",ptr->data);
				ptr=ptr->nxt;
				}
	printf("NULL\n");
}
void check(node const*p)
{
	if(p==NULL){
			puts("Not able to allocate\n");
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
     printf("Deleted all nodes\n");
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
	printf("deleted %p node\n",ptr);
	free(ptr);
	
}
void deletefrompos(node **head,int pos)
{
	node *temp;
	node *ptr;
	temp=*head;
	int i;
	if(*head==NULL){
				puts("Linked list is empty");
				return ;
				}
	else if(pos<=listcount(*head)){
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
		puts("Deletion cannot be possible");
		}
}
int listcount(node const*head)
{
	int count=0;
	node const*ptr;
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
			printf("NULL");
			return;
			}
	reversedisplay(head->nxt);
	printf("<--%d",head->data);
}
int duplicate(node const*head,int val)
{
	node const*ptr=head;
	while(ptr!=NULL){
	if(ptr->data==val){
	  return 1;
	}
	ptr=ptr->nxt;
	}
	return 0;
}
int menu()
{
	int ch;
	puts("\n\n\t\t\tlinked list\n1. Sorted Insert\n2. Display\n3. List count\n4. delete last node\n5. delete from beg\n6. delete from pos\n7. reverse display\n");
	scanf("%d",&ch);
	return ch;
}
