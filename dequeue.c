/*Q5. Write a C/C++ program to implement dequeue(doubly endded
queue) data structure using array.
	Author:Bhoomik Gupta*/
#include<stdio.h>
#define MAX 10
int deleteRight(int dequeue[],int *left,int *right);
int deleteLeft(int dequeue[],int *left,int *right);
char menu();
void insertRight(int dequeue[],int val,int *left,int *right);
void insertLeft(int dequeue[],int val,int *left,int *right);
void display(int dequeue[],int *left,int *right);
int main()
{
	int flag=1;
	char ch;
	int val;
	int dequeue[MAX];
	int left=-1;
	int right=-1;
	while(flag){
			ch=menu();
			switch(ch){
				case 1:
				printf("Enter the number");
				scanf("%d",&val);
				insertRight(dequeue,val,&left,&right);
				break;
				case 2:
				printf("Enter the number");
				scanf("%d",&val);
				insertLeft(dequeue,val,&left,&right);
				break;
				case 3:
				val=deleteLeft(dequeue,&left,&right);
				if(val!=-1){
					printf("The left deleted element=%d",val);
					}
				break;
				case 4:
				val=deleteRight(dequeue,&left,&right);
				if(val!=-1){
					printf("The right deleted element=%d",val);
					}
				break;
				case 5:
				display(dequeue,&left,&right);
				break;
				case 6:
				flag=0;
				break;
			}
	}

}
char menu()
{
	char ch;
	puts("\n\t\t\tdequeue\n1.insert at right\n2. insert at left\n3. delete from left\n4. delete from right\n5. display\n6. quit");
	scanf("%hhd",&ch);
	return ch;
}
void insertRight(int dequeue[],int val,int *left,int *right)
{
	if((*left==0 && *right==MAX-1)||(*left==*right+1)){
		puts("Overflow");
		return ;
	}
	if(*left==-1){
		*left=0;
		*right=0;
	}
	else{
		if(*right==MAX-1){
			*right=0;
		}
		else{
			*right=*right+1;
		}
	}
	dequeue[*right]=val;
}
void insertLeft(int dequeue[],int val,int *left,int *right)
{
	if((*left==0 && *right==MAX-1)||(*left==*right+1)){
		puts("Overflow");
		return ;
	}
	if(*left==-1){
		*left=0;
		*right=0;
	}
	else{
		if(*left==0){
			*left=MAX-1;
		}
		else{
			*left=*left-1;
		}
	}
	dequeue[*left]=val;
}
void display(int dequeue[],int *left,int *right)
{
	int front=*left;
	int rear=*right;	
	if(front==-1){
		puts("Queue is empty");
		return ;
	}
	puts("The elements of queue are");
	if(front<=rear){
		while(front<=rear){
			printf("%d ",dequeue[front]);
			front++;
		}
	}
	else{
		while(front<=MAX-1){
			printf("%d ",dequeue[front]);
			front=front+1;
		}
		front=0;
		while(front<=rear){
			printf("%d ",dequeue[front]);
			front++;
		}
	}	
}
int deleteLeft(int dequeue[],int *left,int *right)
{
	int val=0;
	if(*left==-1){
		puts("Underflow");
		return -1;
	}
	val=dequeue[*left];
	if(*left==*right){
		*left=-1;
		*right=-1;
	}
	else{
		if(*left==MAX-1){
			*left=0;		
		}
		else{
			*left=*left+1;
		}
	}
	return val;
}
int deleteRight(int dequeue[],int *left,int *right)
{
	int val;
	if(*left==-1){
		puts("Underflow");
		return -1;
	}
	val=dequeue[*left];
	if(*left==*right){
		*left=-1;
		*right=-1;
	}
	else{
		if(*right==0){
			*right=MAX-1;		
		}
		else{
			*right=*right+1;
		}
	}
	return val;
}
