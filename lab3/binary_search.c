/*WAP to accept elements of an array using rand() function and perform binary search in it. Compute the time taken by the search function for different array sizes. 
The array sizes should be 100,500,1000,1500,4000,5000,6000,8000,10000*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int binary_search(int *arr, int n,int low,int high,int mid, int element)
{
 	
 	if(low > high)
 		return -1;
 	else
 	{
 		if(arr[mid] == element)
 			return mid+1;
 		else if(element > arr[mid])
 		{
 			low = mid+1;
 			mid = (low+high)/2;
 			return binary_search(arr, n, low, high, mid , element);
 		}
 		else
 		{
 			high = mid-1;
 			mid = (low+high)/2;
 			return binary_search(arr, n, low, high, mid , element);
 		}
 	}

 	
}


void sort(int *arr, int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] < arr[minIndex]) 
            {
                minIndex = j;
            }
        }

        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
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
		arr[i] = rand()%100;
	}

	int low = 0, high = n-1, mid = (low+high)/2;

	printf("Enter the element you want to search:	");
	int element;
	scanf("%d",&element);

	sort(arr, n);



	double time_array;
	double processor_timearray;
	clock_t start,stop;

	start = clock();
	int pos = binary_search(arr , n, low, high, mid,element);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;

	if(pos == -1)
		printf("\nElement not found in the array");
	else
		printf("\nElement found in the array at pos: %d",pos);

	printf("\nTime taken: %lf",time_array);
	printf("\nTime taken: %lf",processor_timearray);
	return 0;
}