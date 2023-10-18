/* wAP to create a function that checks for each element of the array if it is a multiple of 3, multiple of 5 or a multiple of 3 and 5 or multiple of neither 3 or 5.
If a multiple of 3 replace the number with 3, if a multiple of 5 replace the number with 5. if multiple of 15 replace it with 15 and if multiple of none replace it with 0.
Compare the times taken to perform the operation for three arrays */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void check_multiple(int *arr,int n) // function to replace multiples of 3,5,15 with 3,5,15 and else as 0
{
	for(int i=0; i<n; i++)
	{
		if(arr[i] % 3 == 0 && arr[i] % 5 != 0)
			arr[i] = 3;
		else if(arr[i] % 3 != 0 && arr[i] % 5 == 0)
			arr[i] = 5;
		else if(arr[i]%3 == 0 && arr[i] % 5 == 0)
			arr[i] = 15;
		else
			arr[i] = 0;
	}
}

int main()//main function
{

	double time_array;
	double processor_timearray;
	clock_t start,stop;
	int n;
	
	printf("Array size; ");
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
	check_multiple(arr1,n);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;
	
	printf("\nNew array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr1[i]);
	}
	
	printf("\nTime taken : %lf",time_array);
	printf("\nTime taken by processor : %lf",processor_timearray);
	return 0;

}