#include<stdio.h>
#define SIZE 6
void insertion_sort(int arr[SIZE]);
void display (int arr[SIZE]);
int main()
{
    int arr[SIZE] = {55,44,22,66,11,33};
    printf("\n Before Sort :\n");
    display(arr);
    insertion_sort(arr);
    printf("\n After Sort :\n");
    display(arr);
    return 0;
}
void insertion_sort(int arr[SIZE])
{
    int i,j,key;
    for(i=1; i < SIZE; i++)
    {
        key = arr[i]; // backup of the i'th element
        for(j = i-1; j >= 0 && key < arr[j];j--)
        {
            // 1. shift arr[j] one step/index ahead
            arr[j+1] = arr[j]; // copy index element to its next index.
            
            //2. decrment j
        }
        // if any of the one conditions from j loop fails
        // copy key to j+1 index
        arr[j+1] = key;
    }
}

void display (int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}

/*
Best case time complexity  : O(n)
Worst / avg case : O(n^2)

space complexity :O(1) constant

*/