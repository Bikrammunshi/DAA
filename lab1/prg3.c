/*Write a program to read ‘n’ integers from a disc file that must contain
some duplicate values and store them into an array. Perform the following operations on the
array. 
a) Find out the total number of duplicate elements. 
b) Find out the most repeating element in the array. 
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	printf("Enter the number of elements you want to read from the file ");
	int n;
	scanf("%d",&n);
	
	FILE *myfile;
	myfile = fopen("array2.txt","r");
	
	int arr[n];
	
	int i=0;
	
	if(myfile == NULL)
	{
		printf("Error opening the file \n");
	}
	
	while (fscanf(myfile, "%d ", &(arr[i])) == 1 && i<=n) 
	{
        	i++;
        }
        
        
        fclose(myfile);
        
        printf("\nThe array is : ");
        for(i=0;i<n;i++)
        {
        	printf("%d ",arr[i]);
        }
        
        int count[n];
        int sum = 0;
        int unique[n];
        
        for(i=0;i<n;i++)
        {
        	count[i]=0;
        	for(int j=0;j<n;j++)
        	{
        		if(arr[i]==arr[j] && j!=i)
        		{
        			int flag=0;
        			int k;
        			for( k=0;k<=i;k++)
        			{
        				if(arr[i] == unique[k])
        				{
        					flag = 1;
        					break;
        				}
        				else
        					flag = 0;
        			}
        			if(flag == 0)
        			{
        				count[i]++;
        				sum++;
        				unique[k]=arr[i];
        			}
        		}
        	}
        }
        
        printf("\nThe total number of duplicate elements are \t%d\n",sum);
        
        int max = count[0];
        int pos = 0;
        for(i=1;i<n;i++)
        {
        	 if(max<count[i])
        	 {
        	 	max = count[i];
        	 	pos = i;
        	 }
        }
        
        printf("\nThe most repeating number is \t%d\n",arr[pos]);
        
        return 0;
}
