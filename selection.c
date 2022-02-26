/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Selection Sort
	Author:Bhoomik Gupta*/
#include<stdio.h>
void display(int A[],int N);
void selectionsort(int arr[], int n);
int small(int arr[],int i,int n);
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
	selectionsort(A,N);
	printf("after sorting\n");
	display(A,N);
}
void selectionsort(int arr[], int n)
{
  int i;
  int pos;
  int temp;
  for(i=0;i<n;i++){
  			pos=small(arr,i,n);
  			temp=arr[i];
  			arr[i]=arr[pos];
  			arr[pos]=temp;
  			printf("after %d pass\n",i+1);
  			display(arr,n);
  			printf("\n\n");
  			}
}
void display(int A[],int N)
{
	int i;
	for(i=0;i<N;i++){
				printf("%d ",A[i]);
				}

}
int small(int arr[],int i,int n)
{
	int k;
	int pos=i;
	int small=arr[i];
	for(k=i+1;k<n;k++){
				if(arr[k]<small){
							small=arr[k];
							pos=k;
							}	
				}
	return pos;
}
