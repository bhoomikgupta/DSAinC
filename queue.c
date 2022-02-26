/*Q3. Write a C/C++ program to implement queue data structure using
array. Implement below metioned functions.
a) add b) delete c) peep d) displayQueue e)isQueueFull
f) isQueueEmpty
	Author:Bhoomik Gupta*/
#include<stdio.h>
#define size 5
void enqueue(int *a,int *front,int *rear,int val);
int dequeue(int *a,int *front,int *rear);
int peep(int *a,int front,int rear);
void display(int *a,int front,int rear);
int check(int *a,int front,int rear,int flag);
int menu();
int main()
{
	int a[size];
	int front=-1;
	int rear=-1;
	int ch;
	int flag=1;
	int val;
	while(flag){
					ch=menu();
					switch(ch){
							case 1:
							puts("Enter value");
							scanf("%d",&val);
							enqueue(a,&front,&rear,val);
							break;
							case 2:
							val=dequeue(a,&front,&rear);
							printf("dequeue element=%d\n",val);
							break;
							case 3:
							peep(a,front,rear);
							break;
							case 4:
							display(a,front,rear);
							break;
							case 5:
							check(a,front,rear,1);
							break;
							case 6:
							check(a,front,rear,0);
							break;
							default:
							puts("Wrong input given");
							break;
								}
					}

}
void enqueue(int *a,int *front,int *rear,int val)
{
	if(*rear==size-1){
				puts("queue overflow");
				return ;
				}
	*rear=*rear+1;
	a[*rear]=val;
	if(*front==-1){
			*front=0;
			}
}
int dequeue(int *a,int *front,int *rear)
{
	int temp=a[*front];
	a[*front]=0;
	if(*front==-1){
					puts("queue underflow");
					return 0;
			}
	if(*front==*rear){
				*front=-1;
				*rear=-1;
				}
	else{
			*front=*front+1;
			}
	return temp;
}
int menu()
{
	int ch;
	puts("\n\t\tQueue using array\n1. Enqueue\n2. dequeue\n3. peep\n4. display queue\n5. is queue full\n6. is queue empty\n");
	scanf("%d",&ch);
	return ch;
}
int peep(int *a,int front,int rear)
{
	int temp=a[front];
	if(front==-1){
					puts("queue underflow");
					return 0;
			}
	return temp;
}
void display(int *a,int front,int rear)
{
	int i;
	for(i=front;i<=rear;i++){
			printf("\t%d",a[i]);
			}
}
int check(int *a,int front,int rear,int flag)
{
	if(flag==1){
					if(rear==size-1){
					puts("queue overflow");
					return 1;
					}
					else{
							puts("queue is not full");
							return 0;
							}
				
			}
	else{
			if(front==-1){
					puts("queue underflow");
					return 1;
				}
			else{
					puts("queue is not empty");
					return 0;
					}
		}
}
