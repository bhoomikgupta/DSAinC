/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(c) Insertion Sort
	Author:Bhoomik Gupta*/
#include<stdio.h>
void display(int A[],int N);
void insertionsort(int arr[],int n);
int main()
{
	int i;
	int N;
	printf("Enter the size of");
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
				scanf("%d",&A[i]);
				}
	insertionsort(A,N);
	printf("after sorting\n");
	display(A,N);
}
void insertionsort(int arr[],int n)
{
  	int i;
  	int j;
  	int temp;
  	for(i=0;i<=n-1;i++){
    				for(j=i+1;j>0&&arr[j-1]>arr[j];j--){
    										temp=arr[j-1];
    										arr[j-1]=arr[j];
    										arr[j]=temp;
    										}
    								printf("After %d pass\n",i+1);
									display(arr,n);
									puts("\n");	
    						}
}
void display(int A[],int N)
{
	int i;
	for(i=0;i<N;i++){
				printf("%d ",A[i]);
				}

}

