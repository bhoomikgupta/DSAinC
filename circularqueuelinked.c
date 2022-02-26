#include<stdio.h>
#include<stdlib.h>
#define maxsize 5; 
typedef struct node{
			int data;
			struct node *nxt;	
			int capacity;		
			}node;
int menu();
void peep(node const*front);
void display(node const*ptr);
int dequeue(node **front,node **rear);
void enqueue(node **front,node **rear,int val);
void destroy(node *front);
int main()
{
	node *front=NULL;
	node *rear=NULL;
	char flag=1;
	char ch;
	int val;
	while(flag){
			ch=menu();
			switch(ch){
					case 1:
					puts("Enter a number");
					scanf("%d",&val);
					enqueue(&front,&rear,val);
					break;
					case 2:
					val=dequeue(&front,&rear);
					printf("value=%d\n",val);
					break;
					case 3:
					peep(front);
					break;
					case 4:
					display(front);
					break;
					case 5:
					destroy(front);
					flag=0;
					break;
					default:
					puts("You have entered wrong input");
					break;
					}
			
			}
}
int menu()
{
	char ch;
	puts("\nqueue using linked list\n1. enqueue\n2. dequeue\n3. peep\n4. display\n5. exit");
	scanf("%hhd",&ch);
	return ch;
}
void enqueue(node **front,node **rear,int val)
{
	node *temp=(node *)malloc(sizeof(node));
	if(!temp){
			puts("Not able to allocate");
			return ;
	}
	temp->data=val;
	temp->nxt=NULL;
	if(*front==NULL){
				*front=temp;
				*rear=temp;
				temp->nxt=temp;
				temp->capacity=maxsize;
				return ;
			}
	else if((*rear)->capacity==1){
		puts("Queue is full");
		return ;
		}
	else{
		temp->nxt=*front;
		temp->capacity=((*rear)->capacity)-1;
		(*rear)->nxt=temp;
		*rear=temp;
		}
}
int dequeue(node **front,node **rear)
{
	int val;
	if(*front==NULL){
				printf("queue is empty\n");
				return 0;
				}
	node *ptr;
	ptr=*front;
	val=ptr->data;
	if((*front)->nxt==*front){
					*front=NULL;
					*rear=NULL;
					return val;
	}
	*front=ptr->nxt;
	(*rear)->nxt=*front;
	free(ptr);
	return val;
}
void destroy(node *front)  
{
     node *temp;         
     while(front->nxt==front) 
     {
          temp=front;
          front=front->nxt;
          free(temp);
     }
}
void peep(node const*front)
{
	if(front==NULL){
				puts("Queue is empty");
				return;
	}
	printf("%d\n",front->data);
}
void display(node const*front)
{
	node const *ptr=front;
	if(ptr==NULL){
				puts("Queue is empty");
				return;
	}
	do{
		printf("%d ",ptr->data);
		ptr=ptr->nxt;
	}while(ptr!=front);
}
