/*Q1. Write a C/C++ program to implement below mentioned Searching
and Sorting Techniques.
(b) quick Sort
	Author:Bhoomik Gupta*/
#include <stdio.h>
#include <stdlib.h>
int split ( int*, int, int ) ;
void quicksort(int *, int , int);
void main( )
{
	
	int *arr, size;
	int i ;
	printf("enter size of the array\n");
	scanf("%d", &size);
	
	arr=(int *)malloc(size * 4);
	printf("Enter element for array\n");
	for(i=0 ; i<size; i++)
	scanf("%d", &arr[i]);

	printf ( "Quick sort.\n" ) ;
	printf ( "\nArray before sorting:\n") ;

	for ( i = 0 ; i <= (size-1) ; i++ )
		printf ( "%d\t", arr[i] ) ;

	quicksort ( arr, 0, size-1 ) ;

	printf ( "\nArray after sorting:\n") ;

	for ( i = 0 ; i <= (size-1) ; i++ )
		printf ( "%d\t", arr[i] ) ;

}

void quicksort ( int a[ ], int lower, int upper )
{
	int i ;
	if ( upper > lower )
	{
		i = split ( a, lower, upper ) ;
		quicksort ( a, lower, i - 1 ) ;
		quicksort ( a, i + 1, upper ) ;
	}
}

int split ( int a[ ], int lower, int upper )
{
	int i, p, q, t ;
	p = lower + 1 ;
	q = upper ;
	i = a[lower] ;

	while ( q >= p )
	{
		while ( a[p] < i )
			p++ ;

		while ( a[q] > i )
			q-- ;

		if ( q > p )
		{
			t = a[p] ;
			a[p] = a[q] ;
			a[q] = t ;
		}
	}
	t = a[lower] ;
	a[lower] = a[q] ;
	a[q] = t ;

	return q ;
}
