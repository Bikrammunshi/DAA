// implement huffman coding using greedy method

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int freq;
    char data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int freq, char data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->freq = freq;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printCodes(struct node *root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL)
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void huffmanCoding(char data[], int freq[], int n)
{
    struct node *left, *right, *top;
    struct node *nodes[n];
    int i, j;
    for (i = 0; i < n; i++)
        nodes[i] = newNode(freq[i], data[i]);
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (nodes[j]->freq > nodes[j + 1]->freq)
            {
                struct node *temp = nodes[j];
                nodes[j] = nodes[j + 1];
                nodes[j + 1] = temp;
            }
        }
    }
    while (n > 1)
    {
        left = nodes[0];
        right = nodes[1];
        top = newNode(left->freq + right->freq, '$');
        top->left = left;
        top->right = right;
        for (i = 0; i < n - 2; i++)
            nodes[i] = nodes[i + 2];
        nodes[n - 2] = top;
        n--;
        for (i = 0; i < n - 1; i++)
        {
            for (j = 0; j < n - 1 - i; j++)
            {
                if (nodes[j]->freq > nodes[j + 1]->freq)
                {
                    struct node *temp = nodes[j];
                    nodes[j] = nodes[j + 1];
                    nodes[j + 1] = temp;
                }
            }
        }
    }
    int arr[100], top1 = 0;
    printCodes(nodes[0], arr, top1);
}

int main()
{
    int n, i;
    printf("Enter the number of characters: ");
    scanf("%d", &n);
    char data[n];
    int freq[n];
    printf("Enter the characters: ");
    for (i = 0; i < n; i++)
        scanf(" %c", &data[i]);
    printf("Enter the frequencies: ");
    for (i = 0; i < n; i++)
        scanf("%d", &freq[i]);
    huffmanCoding(data, freq, n);
    return 0;
}
