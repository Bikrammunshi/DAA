//implement heapsort in c

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a,int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int *a,int n,int i)
{

	int largest = i;
	int l = 2*i;
	int r = 2*i+1;

	if(l<n && a[l] > a[largest])
		largest = l;

	if(r<n && a[r]>a[largest])
		largest = r;

	if(largest != i)
	{
		swap(&a[i],&a[largest]);
		heapify(a,n,largest);
	}
}

void heap_sort(int *A,int n)
{
	for(int i = n/2; i>=0 ;i--)
		heapify(A,n,i);
	for(int i= n-1; i>=0; i--)
	{
		swap(&A[0],&A[i]);
		heapify(A,i,0);
	}
}


int main()
{
	printf("Enter the size of the array:	");
	int n;
	scanf("%d",&n);

	int arr[n];
	printf("Enter the elements of the array: ");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}

	double time_array;
	double processor_timearray;
	clock_t  start,stop;

	start = clock();
	heap_sort(arr,n);
	stop = clock();

	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;
	
	printf("\nTime taken: %lf",time_array);
	printf("\nTime taken: %lf",processor_timearray);

	printf("\nThe sorted array is : ");
	for(int i=0;i<n;i++)
		printf("%d ",arr[i]);

	return 0;
}
