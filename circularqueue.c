/*Q4. Write a C/C++ program to implement circular queue data
structure using array. Implement below metioned functions.
a) add b) delete c) peep d) displayQueue e)isQueueFull
f) isQueueEmpty
	Author:Bhoomik Gupta*/
#include<stdio.h>
#define size 5
int menu();
void enqueue(int *a,int *front,int *rear,int val);
int dequeue(int *a,int *front,int *rear);
void display(int *a,int front,int rear);
int peep(int *a,int front,int rear);
int check(int *a,int front,int rear,int flag);
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
							val=check(a,front,rear,1);
							if(val==1){
								puts("Queue overflow");
								}
							else{
									puts("enqueue is possible");
								}
							break;
							case 6:
							val=check(a,front,rear,0);
							if(val==1){
								puts("Queue underflow");
							}
							else{
									puts("dequeue is possible");
								}
							break;
							default:
							puts("Wrong input given");
							break;
								}
					}
}
int menu()
{
	int ch;
	puts("\n\t\tQueue using array\n1. Enqueue\n2. dequeue\n3. peep\n4. display queue\n5. is queue full\n6. is queue empty\n");
	scanf("%d",&ch);
	return ch;
}
void enqueue(int *a,int *front,int *rear,int val)
{
	if((*front==0)&&(*rear==size-1)){
			puts("Overflow");
			} 
	else if((*front==-1)&&(*rear==-1)){
		*front=0;
		*rear=0;
		}
	else if((*rear==size-1)&&(*front!=0)){
		*rear=0;
		}
	else{
		*rear=*rear+1;
	}
	a[*rear]=val;
}
int dequeue(int *a,int *front,int *rear)
{
	int val;
	if(*front==-1){
		puts("Underflow");
		return 0;
	}
	val=a[*front];
	if(*front==*rear){
		*front=-1;
		*rear=-1;
	}
	else{
		if(*front==size-1){
			*front=0;
		}
		else{
			*front=*front+1;
		}
	}
	return val;
}
void display(int *a,int front,int rear)
{
	 int i;
	 if (front==-1){
        puts("Queue is underflow");
        return;
    }
    puts("Elements in Circular Queue");
    if (rear>=front){
        for(i=front;i<=rear;i++)
            printf("%d ",a[i]);
    }
    else{
        for (i=front;i<size;i++)
            printf("%d ", a[i]);
 
        for (i=0;i<=rear;i++)
            printf("%d ", a[i]);
    }
}
int peep(int *a,int front,int rear)
{
	if (front==-1){
        puts("Queue is underflow");
        return 0;
    }
    return a[front];
}
int check(int *a,int front,int rear,int flag)
{
	if(flag==1){
			if((front==0)&&(rear==size-1)){
			return 1;
			}
			else{
					return 0;
				}
			 
		}
	else{
			if(front==-1){
				return 1;
			}
			else{
				return 0;
			}	
	}
}
