/* WAP to create a function to search an element in array using linear search.
Take three arrays of 3 different sizes and calculate the time taken to search an element in each case.
Compare the time taken by the function to search in the array of different sizes */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void search(int *arr, int n,int c) //function to perform a linear seach
{
	int pos=0;
	for(int i=0;i<n;i++)
	{
		if(*(arr+i) == c)
		{
			pos = i;
			break;
		}
	}
	printf("\n The number is found at position: %d",pos+1);
}

int main()//main function
{
	double time_array;
	double processor_timearray;
	clock_t start,stop;
	int n;
	int element;

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
	
	printf("\n Enter an element to search in the array: ");
	scanf("%d",&element);

	start = clock();
	search(arr1,n,element);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;
	
	printf("\nTime taken : %lf",time_array);
	printf("\nTime taken by processor : %lf",processor_timearray);
	
		
	return 0;
}
