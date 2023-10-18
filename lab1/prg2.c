/*Given an array arr[] of size N, find the prefix sum of the array. A prefix
sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is
arr[0] + arr[1] + arr[2] . . . arr[i].
*/

#include <stdio.h>

int main()
{
	printf("Enter the size of the array ");
	int n;
	scanf("%d",&n);
	
	int arr[n];
	printf("Enter the elements of the character\n");
	
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	
	int arr2[n];
	
	for(int i=0;i<n;i++)
	{
		arr2[i]=0;
		for(int j=0;j<=i;j++)
		{
			arr2[i]=arr2[i]+arr[j];
		}
	}
	
	printf("The elements of the original array \n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr[i]);
	}
	
	printf("The elements of the prefix array \n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",arr2[i]);
	}
	
	return 0;
}
