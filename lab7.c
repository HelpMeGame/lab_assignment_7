/*

COP 3502: Computer Science 1

lab7.c

Keagan Bowman, 3/8/2024

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int data;
    int swapCount;
} Node;

void printArray(Node *arr, int n)
{
    // loop through and print out array contents
    for (int i = 0; i < n; i ++)
    {
        printf("%d ", arr[i].data);
    }

    printf("\n");
}

void printArraySwaps(Node *arr, int n)
{
    // loop through and print out array contents
    for (int i = 0; i < n; i ++)
    {
        printf("\n\t> %d: %d", arr[i].data, arr[i].swapCount);
    }
}

void bubbleSort(Node *arr, int n)
{
    int totalSwaps = 0;
    Node k;
    // loop through array for bubble sort
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].data > arr[j+1].data)
            {
                k = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = k;

                // increment swap counts
                arr[j].swapCount++;
                arr[j+1].swapCount++;
                totalSwaps++;
            }
        }
    }
    // print out array swap counts
    printArraySwaps(arr, n);
    // print total swap count
    printf("\n\t> total # of swaps: %d", totalSwaps);
}

int* selectionSort(Node *arr, int n)
{
    // set temp values
    int minIndex;
    int totalSwaps = 0;
    Node k;

    // loop through array
    for (int i = 0; i < n-1; i++)
    {
        // set min index
        minIndex = i;
        
        // loop through and find lower value
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j].data < arr[minIndex].data)
            {
                minIndex = j;
            }
        }

        // swap nodes
        k = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = k;

        // increment swap counters
        arr[i].swapCount++;
        arr[minIndex].swapCount++;
        totalSwaps++;
    }

    // print out values
    printArraySwaps(arr, n);
    printf("\n\t> total # of swaps: %d", totalSwaps);
}

Node* intArrayToNodeArray(int arr[], int n)
{
    // allocate node space
    Node *nodeArr = (Node*)calloc(n, sizeof(Node));

    // check to make sure allocation was successful
    if (nodeArr == NULL)
    {
        printf("\nUnable to allocate space for node array.");
        exit(1);
    }

    // set node values
    for (int i = 0; i < n; i++)
    {
        nodeArr[i].data = arr[i];
    }

    return nodeArr;
}


int main()
{
    // create arrays and get sizes
    int intArray1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array1Size = sizeof(intArray1) / sizeof(int);

    int intArray2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int array2Size = sizeof(intArray2) / sizeof(int);

    // handle array 1 sorts
    printf("array 1:\n\nbubble sort:");

    // get array 1
    Node *nodeArray = intArrayToNodeArray(intArray1, array1Size);
    
    // doo bubble sort on array 1
    bubbleSort(nodeArray, array1Size);

    // reset array 1
    nodeArray = intArrayToNodeArray(intArray1, array1Size);

    printf("\n\nselection sort:");

    // do selection sort on array 1
    selectionSort(nodeArray, array1Size);

    // handle array 2 sorts
    printf("\n\n\narray 2:\n\nbubble sort:");
    
    // free node array 1
    free(nodeArray);

    // get array 2
    nodeArray = intArrayToNodeArray(intArray2, array2Size);
    
    // do bubble sort on array 2
    bubbleSort(nodeArray, array2Size);

    // reset array 2
    nodeArray = intArrayToNodeArray(intArray2, array2Size);

    printf("\n\nselection sort:");

    // do selection sort on array 2
    selectionSort(nodeArray, array2Size);

    // free node array 2
    free(nodeArray);
}