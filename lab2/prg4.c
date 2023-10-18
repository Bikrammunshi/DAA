/* Create a function that acceps an array of decimal numbers and converts each element of the array into its equivalent binary number.
Take arrays of 3 different sizes and calculate the time taken to do the conversion in each case.
Compare the time taken by the function to conver the arrays of different sies */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void  convert_array_to_binary(int *arr,int n)
{
	int r,m=1,bin=0;
	for(int i=0;i<n;i++)
	{
		m=1,bin=0;
		while(arr[i]!=0)
  		{
    		r = arr[i]%2;
    		bin = bin + (r * m);
    		m = m * 10;
    		arr[i] = arr[i] / 2;
  		}

  		arr[i]=bin;
  	}
}

int main()//main function
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
	convert_array_to_binary(arr1,n);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;
	
	printf("\nConverted binary array : ");
	for(int i=0;i<n;i++)
	{
		printf("%d ",arr1[i]);
	}
	
	printf("\nTime taken : %lf",time_array);
	printf("\nTime taken by processor : %lf",processor_timearray);
	return 0;
}