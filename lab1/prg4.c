/* Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2
elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &
q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated.*/

#include <stdio.h>
#include <stdlib.h>

void EXCHANGE(int *p,int *q)
{
	int tmp;
        tmp = *p;
        *p=*q;   
        *q=tmp;
}

int* ROTATE_RIGHT(int *arr,int n)
{
	  
        	int j, last;    
        	last = *(arr+n-1);    
       	        for(j = n-1; j > 0; j--)
       	        {    
                	EXCHANGE((arr+j),(arr+j-1));    
           	}
        	EXCHANGE((arr+0),&last);    
    		return arr;
}

int main()
{
	int *arr;
	int n;
	printf("Enter the number of the elements you want to enter ");
	scanf("%d",&n);
	
	arr = (int *) malloc(n*sizeof(int));
	
	printf("Enter the elements of the array \n");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",(arr+i));
	}
	
	int c;
	printf("Enter the number of digits you want to rotate ");
	scanf("%d",&c);
	
	printf("The elements of the original array ");
	
	for(int i=0;i<n;i++)
	{
		printf(" %d",*(arr+i));
	}
	
	
	arr = ROTATE_RIGHT(arr,c);
	
	
	printf("\nThe elements of the new array ");
	for(int i=0;i<n;i++)
	{
		printf(" %d",*(arr+i));
	}
	
	return 0;
}
	
