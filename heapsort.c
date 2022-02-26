/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(c)heapsort
	Author:Bhoomik Gupta
*/
#include <stdio.h>
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printArray(int arr[], int n);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);
int main() 
{
    int n;
    int i;
    printf("Enter the no. of elements");
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++){
    	scanf("%d",&arr[i]);
    	}
    puts("Input array");
    printArray(arr, n);
    heapSort(arr, n);
    printf("Sorted array is \n");
    printArray(arr, n);
}
void printArray(int arr[], int n) 
{
    for (int i = 0; i < n; ++i)
      printf("%d ", arr[i]);
    printf("\n");
}
void heapify(int arr[], int n, int i) 
{
    // Find largest among root, left child and right child
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
      largest = left;
  
    if (right < n && arr[right] > arr[largest])
      largest = right;
  
    // Swap and continue heapifying if root is not largest
    if (largest != i) {
      swap(&arr[i], &arr[largest]);
      heapify(arr, n, largest);
    }
}
  
  // Main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
      heapify(arr, n, i);
  
    // Heap sort
    for (int i = n - 1; i >= 0; i--) {
      swap(&arr[0], &arr[i]);
  
      // Heapify root element to get highest element at root again
      heapify(arr, i, 0);
    }
}
