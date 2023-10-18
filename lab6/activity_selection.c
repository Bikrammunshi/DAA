// implement the activity selection problem using greedy method

#include <stdio.h>
#include <stdlib.h>

void activitySelection(int s[], int f[], int n)
{
    int i, j;
    printf("Selected activities are: ");
    i = 0;
    printf("%d ", i);
    for (j = 1; j < n; j++)
    {
        if (s[j] >= f[i])
        {
            printf("%d ", j);
            i = j;
        }
    }
}

int main()
{
    int n, i;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    int s[n], f[n];
    printf("Enter the start time of the activities: ");
    for (i = 0; i < n; i++)
        scanf("%d", &s[i]);
    printf("Enter the finish time of the activities: ");
    for (i = 0; i < n; i++)
        scanf("%d", &f[i]);
    activitySelection(s, f, n);
    return 0;
}
