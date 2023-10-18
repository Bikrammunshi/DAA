//WAP to perform quick sort in an array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition(int *A, int p,int r)
{
	int x = A[r];
	int L = p - 1;
	int i=p-1;
	for(int j=p; j<r;j++)
	{
		if(A[j] <= x)
		{
			i = i+1;
			int temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}

	int temp = A[i+1];
	A[i+1] = A[r];
	A[r] = temp;

	return i+1;
}
void quicksort(int *A, int p, int r)
{
	if(p < r)
	{
		int q = partition(A,p,r);
		quicksort(A,p,q-1);
		quicksort(A,q+1,r);
	}
}

int main()
{
	printf("Enter the size of the array:	");
	int n;
	scanf("%d",&n);

	int *arr = malloc(n * sizeof(int));
	for(int i=0;i<n;i++)
	{
		arr[i] = rand()%100;	}

	

	double time_array;
	double processor_timearray;
	clock_t start,stop;

	start = clock();
	quicksort(arr , 0, n-1);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;

	printf("\nTime taken: %lf",time_array);
	printf("\nTime taken: %lf",processor_timearray);
	return 0;
}