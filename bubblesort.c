/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Bubble Sort
	Author:Bhoomik Gupta*/
#include<stdio.h>
void display(int A[],int N);
void bubbleSort(int arr[], int n);
int main()
{
	int i=0;
	int N;
	printf("Enter the size of");
	scanf("%d",&N);
	int A[N];
	for(i=0;i<N;i++){
				scanf("%d",&A[i]);
				}
	bubbleSort(A,N);
	printf("after sorting\n");
	display(A,N);
}
void bubbleSort(int arr[], int n)
{
   int i; 
   int j;
   int temp=0;
   for (i = 0; i < n-1; i++){     
			for (j = 0; j < n-i-1; j++){
					if (arr[j] > arr[j+1]){
							temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;		
									}
				      			}
				      	printf("After %d pass\n",i+1);
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
