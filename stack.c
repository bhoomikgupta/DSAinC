/*Q2. Write a C/C++ program to implement stack data structure using
array. Implement below metioned functions.
a) push b) pop c) peep d) displayStack e)isStackFull
f) isStackEmpty
	Author:Bhoomik Gupta*/
#include<stdio.h>
#define size 10
void displayStack(int *a,int top);
void push(int *a,int *top,int val);
int pop(int *a,int *top);
int display();
int check(int *a,int top,int flag);
int peep(int *a,int top);
int main()
{
	int a[size];
	int top=-1;
	int ch;
	int flag=1;
	int val;
	while(flag){
			ch=display();
			switch(ch){
						case 1:
								puts("Enter the number");
								scanf("%d",&val);
								push(a,&top,val);
								break;
						case 2:
								val=pop(a,&top);
								printf("Popped val=%d",val);
								break;
						case 3:
								val=peep(a,top);
								printf("Peeped value=%d\n",val);
								break;
						case 4:
								displayStack(a,top);
								break;
						case 5:	
								val=check(a,top,1);
								if(val==1){
											puts("Stack overflow");
											}
								break;
						case 6:
								val=check(a,top,0);
								if(val==1){
											puts("Stack underflow");
											}
								break;
						default:
								puts("Wrong input is given");
								break;
					}	
			}

}
int display()
{
	int ch;
	puts("\n\t\tStack using array\n1. Push\n2. Pop\n3. Peep\n4. Displaystack\n5. Is stack full\n6. Is Stack Empty\n");
	scanf("%d",&ch);
	return ch;
}
void push(int *a,int *top,int val)
{
	if(*top==size-1){
						puts("Stack Overflow");
						return;
						}
	*top=*top+1;
	a[*top]=val;
	puts("Successfully pushed an element");
}
int pop(int *a,int *top)
{
	if(*top==-1){
			puts("Stack Underflow");
			return 0;
				}
	int temp;
	temp=a[*top];
	a[*top]=0;
	*top=*top-1;
	return temp;
}
void displayStack(int *a,int top)
{
	int i;
	for(i=top;i>=0;i--){
			printf("%d ",a[i]);
			}
}
int peep(int *a,int top)
{
	if(top==-1){
			puts("Stack Underflow");
			return 0;
				}
	int temp;
	temp=a[top];
	return temp;
}
int check(int *a,int top,int flag)
{
	if(flag==1){
				if(top==size-1){
						return 1;
						}
				else{
						return 0;
						}	
			}
	else{
			if(top==-1){
					return 1;
					}
			else{
						return 0;
						}	
			
			}	

}
