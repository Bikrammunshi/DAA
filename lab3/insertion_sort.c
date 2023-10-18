/*WAP to accept elements of an array using rand() function and perform insertion sort on it. COmpute the time taken by the sort function for different array sizes*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertion_sort(int *arr, int n) 
{
	int key;
	for(int j=1;j<n;j++)
	{
		key = arr[j];
		int i=j-1;
		while(i>-1 && arr[i]>key)
		{
			arr[i+1] = arr[i];
			i = i-1;
		}

		arr[i+1] = key;


	}
}

int main()
{
	printf("Enter the size of the array:	");
	int n;
	scanf("%d",&n);

	int arr[n];
	for(int i=0;i<n;i++)
	{
		arr[i] = rand()%100;	}

	

	double time_array;
	double processor_timearray;
	clock_t start,stop;

	start = clock();
	insertion_sort(arr , n);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;

	printf("\nTime taken: %lf",time_array);
	printf("\nTime taken: %lf",processor_timearray);
	return 0;
}