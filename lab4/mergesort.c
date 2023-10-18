//WAP to perform merge sort in an array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void merge(int *A,int p,int q,int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;

	int L[n1];
	int R[n2];

	for(int i=0; i<n1 ; i++)
	{
		L[i] = A[p + i - 1];
	}

	for(int j=0; j<n2; j++)
	{
		R[j] = A[q + j];
	}

	int i=0,j=0;

	for(int k=p; k<=r; k++)
	{
		if(L[i] < R[j])
		{
			A[k] = L[i];
			i++;
		}

		else

		{
			A[k] = R[j];
			j++;
		}
	}
}

void mergesort(int *A,int p,int r)
{
	if( p < r)
	{
		int q = ((p + r) / 2);
		mergesort(A,p,q);
		mergesort(A, q + 1 , r);
		merge(A,p,q,r);
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
	mergesort(arr , 0, n);
	stop = clock();
	
	time_array = (double)stop - (double)start;
	processor_timearray = time_array / CLOCKS_PER_SEC;

	printf("\nTime taken: %lf",time_array);
	printf("\nTime taken: %lf",processor_timearray);
	return 0;
}