/* Write a program to find out the second largest and second smallest number stored in an array of n integers*/

#include <stdio.h>
#include <stdlib.h>

int n = 0;

int main()
{
	FILE *myfile;
	myfile = fopen("array.txt","r");
	
	int arr[100];
	
	if(myfile == NULL)
	{
		printf("Error opening the file \n");
	}
	
	while (fscanf(myfile, "%d,", &(arr[n])) == 1) 
	{
        	n++;
        }
        
        
        fclose(myfile);
        
        printf("The numbers in the array are \n");
        for(int i=0;i<n;i++)
        {
        	printf("%d\n",arr[i]);
        }
	int largest = arr[0];
	int second_largest = arr[1];
	int temp;
	
	if ( largest < second_largest)
	{
		temp = largest;
		largest = second_largest;
		second_largest = temp;
	}
	
	for (int i = 2; i < n; i++)
    	{
	        if (arr[i] > largest)
	        {
	            second_largest = largest;
	            largest = arr[i];
	        }
	        else if (arr[i] > second_largest && arr[i] != largest)
	        {
	            second_largest = arr[i];
	        }
	}
	
	printf("The second largest number of the array is %d \n",second_largest);

	int smallest = arr[0];
	int second_smallest = arr[1];
	
	if ( smallest > second_smallest)
	{
		temp = smallest;
		smallest = second_smallest;
		second_smallest = temp;
	}
	
	for (int i = 2; i < n; i++)
    	{
	        if (arr[i] < smallest)
	        {
	            second_smallest = smallest;
	            smallest = arr[i];
	        }
	        else if (arr[i] < second_smallest && arr[i]!= smallest)
	        {
	            second_smallest = arr[i];
	        }
	}
	
	printf("The second smallest number of the array is %d \n",second_smallest);
	
	return 0;
}
