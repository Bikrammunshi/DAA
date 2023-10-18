/* WAP to create a function to reverse an array. Take arrays of 3 different sizes and calculate the time taken to reverse the array to each case
Compare the time taken by the function to reverse the arrays of different sizes */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void reversal(int *arr,int n)
{
	for(int i=0; i<n/2; i++)
	{
		int temp = *(arr+i);
		*(arr+i) = *(arr+n-i-1);
		*(arr+n-i-1) = temp;
	}
}

int main()
{
	double time_array;
	double processor_timearray;
	clock_t start,stop;
	int n;
	
	
	printf("Array  size :");
	scanf("%d",&n);
	int arr1[n];
	
	printf("Enter the elements of the array ");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr1[i]);
	}
	
	printf("\nOriginal array : ");
	
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr1[i]);
	}
	
	start = clock();
	reversal(arr1,n);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;
	
	printf("\nReversed array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr1[i]);
	}
	
	printf("\nTime taken : %lf",time_array);
	printf("\nTime taken by processor : %lf",processor_timearray);
	return 0;
}
