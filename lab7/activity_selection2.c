// Implement Activity selection for a given set of activities for which deadlines and profits are given. Also compute the profit obtained.

#include <stdio.h>
#include <stdlib.h>

struct activity
{
    int start;
    int finish;
    int profit;
};

void swap(struct activity *a, struct activity *b)
{
    struct activity temp = *a;
    *a = *b;
    *b = temp;
}

void sort(struct activity arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - 1 - i; j++)
            if (arr[j].finish > arr[j + 1].finish)
                swap(&arr[j], &arr[j + 1]);
}

void activitySelection(struct activity arr[], int n)
{
    sort(arr, n);
    int i, j;
    printf("Selected activities: ");
    printf("%d ", 0);
    i = 0;
    for (j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            printf("%d ", j);
            i = j;
        }
    }
    printf("\n");
}

int main()
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    struct activity arr[n];
    printf("Enter the start, finish and profit of each activity:\n");
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &arr[i].start, &arr[i].finish, &arr[i].profit);
    activitySelection(arr, n);
    int profit = 0;
    for (int i = 0; i < n; i++)
        profit += arr[i].profit;
    printf("Total profit: %d\n", profit);
    return 0;
}
