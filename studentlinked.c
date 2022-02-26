/*Q4. Write a C/C++ program to implement single linked list to store
Student Information ( StudentName and StudentPRN).
Implement below metioned functions. Apply all required condition
check & validation like list empty or not, while inserting/deleting by
position validate the position.
a)insertAtEnd b) insertAtBeg c) insertAtPos d) displayList
e)listNodeCount f) deleteFromEnd g) deleteFromBeg
h)deleteFromPos i) deleteByElement j) reverseDisplay
k)freeAllNode
	Author:Bhoomik Gupta*/
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
			int roll;
			char name[30];
			struct node *nxt;			
			}node;
void sortedinsert(node **head);
void display(node const*ptr);
void destroy(node *head); 
void check(node *p);
int duplicate(node *head,int roll);
node *search(node *head,int val);
void modify(node *ptr,int val);
void deletefrombeg(node **head);
void delete(node **head,int val);
void insertatbeg(node **head);
void insertatpos(node **head,int pos);
void deletefrompos(node **head,int pos);
int listcount(node const*head);
void reversedisplay(node const*head);
void deletebyelement(node **head,int val);
int menu(); 
int main()
{
	node *head=NULL;
	node *ptr=NULL;
	int ch;
	int flag=1;
	int val;
	while(flag){
			ch=menu();
			switch(ch){
					case 1:
						sortedinsert(&head);
						break;
					case 2:
						display(head);
						break;
					case 3:
						printf("Enter the roll no. that u want to search");
						scanf("%d",&val);
						ptr=search(head,val);
						if(ptr!=NULL){
								printf("roll no. found in list\n");
								ptr=NULL;
								}
						else{
							printf("Not found in list\n");
							}
						break;
					case 4:
						printf("Enter the roll no. that u want to search");
						scanf("%d",&val);
						ptr=search(head,val);
						if(ptr!=NULL){
								printf("roll found in linked list\n");
								modify(ptr,1);
								ptr=NULL;
								}
						else{
							printf("Not found in linkedlist\n");
							}
						break;
					case 5:
						printf("Enter the roll no. that u want to delete");
						scanf("%d",&val);
						deletebyelement(&head,val);
						printf("Deleted successfully\n");
						break;
					case 6:
						destroy(head);
						printf("List deleted");
						break;
					case 7:
						deletefrompos(&head,listcount(head));
						break;
					case 8:
						printf("Enter the position");
						scanf("%d",&val);
						deletefrompos(&head,val);
						break;
					case 9:
						deletefrombeg(&head);
						break;
					case 10:
						reversedisplay(head);
						break;
					case 11:
						listcount(head);
						break;
					case 12:
						insertatpos(&head,listcount(head)+1);
						break;
					case 13:
						insertatbeg(&head);
						break;	
					case 14:
						printf("Enter the position");
						scanf("%d",&val);
						insertatpos(&head,val);
						break;
					case 15:
						destroy(head);
						printf("List deleted");
						flag=0;
						break;
					default:
						printf("You have entered wrong input\n");
						break;
					
					}	
	}


}
int menu()
{
	int ch;
	printf("\n\n\t\t\tStudent linked list\n1. Sorted Insertion of data\n2. display\n3. Find roll\n4. Modify\n5. Delete a node with Roll no.\n6. delete complete data\n7. delete from end\n8. delete from pos\n9. delete from beg\n10. reverse display\n11. list node count\n12. insert at end\n13. insert at beg\n14. insert at pos\n15. exit\n");
	scanf("%d",&ch);
	return ch;
}
void sortedinsert(node **head)
{
	node *ptr;
	ptr=*head;
	int flag=0;
	node *preptr;
	node *temp=(node *)malloc(sizeof(node));
	check(temp);
	modify(temp,0);
	flag=duplicate(*head,temp->roll);
	if (flag==1){
			printf("Duplicacy found in list\n");
			return ;
			}
	else{
		if(*head!=NULL){
			if(ptr->roll > temp->roll){
						temp->nxt=ptr;
						*head=temp;
						}
			else{		
				while(ptr->roll <= temp->roll &&ptr->nxt!=NULL){
											preptr=ptr;
											ptr=ptr->nxt;
											}
					if(ptr->roll > temp->roll){		
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
				}
	
	printf("Succesfully insertion of data\n");
				
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
void display(node const *ptr)
{
	printf("\n\nStudent list\n");
	while(ptr!=NULL){
				printf("%d %s--->",ptr->roll,ptr->name);
				ptr=ptr->nxt;
				}
	printf("NULL\n");
}
int duplicate(node *head,int roll)
{
	node *ptr=head;
	while(ptr!=NULL){
	if(ptr->roll==roll){
	  return 1;
	}
	ptr=ptr->nxt;
	}
	return 0;
}
node *search(node *head,int val)
{
	node *ptr;
	ptr=head;
	while(ptr!=NULL){
				if(ptr->roll==val){
							return ptr;
							}
				else{
					ptr=ptr->nxt;
					}
				}
}
void modify(node *ptr,int fun)
{
	if(fun==1){
		printf("You are modifying %d roll no. details\n",ptr->roll);
		printf("Stored Name :%s\n",ptr->name);
		printf("Enter ur name\n");
		scanf("%s",ptr->name);
		printf("Successfully changed the name\n");
	}
	else{
		printf("Student details\n");
		printf("Enter name ");
		scanf("%s",ptr->name);
		printf("Enter ur roll no. ");
		scanf("%d",&ptr->roll);
		}
}
void deletebyelement(node **head,int val)
{
	node *ptr;
	node *preptr;
	ptr=*head;
	
				if(ptr->roll==val){
							deletefrombeg(head);
							return ;
							}
				else{
					while(ptr->roll!=val){
								preptr=ptr;
								ptr=ptr->nxt;
								}
								preptr->nxt=ptr->nxt;
								free(ptr);
					}
		
}
void deletefrombeg(node **head)
{
	if(*head==NULL){
				puts("Linked list is empty\n");
				return;
				}
	node *ptr;
	ptr=*head;
	*head=ptr->nxt;
	free(ptr);
}
void reversedisplay(node const*head)
{

	if(head==NULL){
			printf("NULL");
			return;
			}
	reversedisplay(head->nxt);
	printf("<--%s ",head->name);
	printf("%d",head->roll);
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
void deletefrompos(node **head,int pos)
{
	node *temp;
	node *ptr;
	temp=*head;
	int i;
	if(*head==NULL){
				puts("Linked list is empty");
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
					printf("Successfully deleted %d node",pos);
					}
	else{
		printf("Deletion cannot be possible");
		}
}
void insertatpos(node **head,int pos)
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
				insertatbeg(head);
				}
		else{
			node *temp=(node *)malloc(sizeof(node));
			check(temp);
			modify(temp,0);
			for(i=0;i<pos-1;i++){
						preptr=ptr;
						ptr=ptr->nxt;
						}
						preptr->nxt=temp;
						temp->nxt=ptr;
			}
			printf("Successfully inserted at position %d",pos);
			}

}
void insertatbeg(node **head)
{
	node *temp;
	temp=(struct node*)malloc(sizeof(node));
	check(temp);
	modify(temp,0);
	temp->nxt=NULL;
	temp->nxt=*head;
	*head=temp;
}
