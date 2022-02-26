/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(a) Merge Sort
	Author:Bhoomik Gupta*/
#include<stdio.h>
#define MAX 50
void mergeSort(int arr[],int low,int mid,int high);
void partition(int arr[],int low,int high);
void display(int arr[],int low,int high);
int x=0;
int main(){
   
    int merge[MAX],i,n;

    printf("Enter the total number of elements: ");
    scanf("%d",&n);

    printf("Enter the elements which to be sort: ");
    for(i=0;i<n;i++){
         scanf("%d",&merge[i]);
    }

    partition(merge,0,n-1);

    printf("After merge sorting elements are: ");
    display(merge,0,n-1);
   return 0;
}

void partition(int arr[],int low,int high){

    int mid;

    if(low<high){
         mid=(low+high)/2;
         partition(arr,low,mid);
         partition(arr,mid+1,high);
         puts("\nleft partition\t\t\tright partition");
         display(arr,low,mid);
         printf("\t\t\t\t");
         display(arr,mid+1,high);
         mergeSort(arr,low,mid,high);
         printf("\nAfter %d pass\n",x+1);
         display(arr,low,high);
         puts("");
         x++;
    }
}

void mergeSort(int arr[],int low,int mid,int high){

    int i,m,k,l,temp[MAX];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)){

         if(arr[l]<=arr[m]){
             temp[i]=arr[l];
             l++;
         }
         else{
             temp[i]=arr[m];
             m++;
         }
         i++;
    }

    if(l>mid){
         for(k=m;k<=high;k++){
             temp[i]=arr[k];
             i++;
         }
    }
    else{
         for(k=l;k<=mid;k++){
             temp[i]=arr[k];
             i++;
         }
    }
   
    for(k=low;k<=high;k++){
         arr[k]=temp[k];
    }
}
void display(int arr[],int low,int high)
{
	int i;
	for(i=low;i<=high;i++){
         printf("%d ",arr[i]);
         }
         
}
