#include<stdio.h>
#include<stdlib.h>
#define size 5
typedef struct node{
			int data;
			struct node *nxt;
			int capacity;			
			}node;
int menu();
void display(node const*ptr);
int peep(node const*top);
void destroy(node *top);
void push(node **top,int val);
int pop(node **top);
int main()
{
	node *top=NULL;
	char flag=1;
	char ch;
	int val;
	while(flag){
			ch=menu();
			switch(ch){
					case 1:
					puts("Enter a number");
					scanf("%d",&val);
					push(&top,val);
					break;
					case 2:
					val=pop(&top);
					printf("popped data=%d\n",val);
					break;
					case 3:
					peep(top);
					break;
					case 4:
					display(top);
					break;
					case 5:
					destroy(top);
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
	puts("\nstack using linked list\n1. push\n2. pop\n3. peep\n4. display\n5. exit");
	scanf("%hhd",&ch);
	return ch;
}
void push(node **top,int val)
{
	node *temp;
	temp=(struct node*)malloc(sizeof(node));
	if(temp==NULL){
		puts("Not able to allocate");
		return	;
	}
	else{
		if(*top==NULL){
				temp->capacity=size;
				temp->data=val;
				*top=temp;
				return;
		}
		else if((*top)->capacity==1){
		puts("Stack is full");
		return ;
		}
		else{
			temp->capacity=((*top)->capacity)-1;
			temp->data=val;
			temp->nxt=*top;
			*top=temp;
			}	
	}
}
int pop(node **top)
{
	int val;
	if(*top==NULL){
				printf("stack is empty\n");
				return 0;
				}
	node *ptr;
	ptr=*top;
	val=ptr->data;
	*top=ptr->nxt;
	free(ptr);
	return val;
}
void display(node const*ptr)
{
	puts("Stack elements");
	if(ptr==NULL){
			puts("Stack is empty");
			return ;
	}
	while(ptr!=NULL){
				printf("%d\n",ptr->data);
				ptr=ptr->nxt;
				}
}
int peep(node const*top)
{
	printf("top data=%d\n",top->data);
}
void destroy(node *top)  
{
     node *temp;         
     while(top!=NULL) 
     {
          temp=top;
          top=top->nxt;
          free(temp);
     }
}

