#include<stdio.h>
#define SIZE 9

int comparisons;
int linear_search(int arr[SIZE],int key) ;
int main()
{
    int arr[SIZE] = {33,55,88,77,44,11,66,22,99};
    // 1. Get the key from the user.
    int key;
    printf("Enter the key to search :");
    scanf("%d",&key);  //33
    int index = linear_search(arr,key);
    if(index == -1)
        printf("Key not Found !\n");
    else
        printf("Key found at index %d\n",index);
        printf("Comparisons = %d\n",comparisons);
    return 0;
}

int linear_search(int arr[SIZE],int key) // 77 --> index 3
{
    // 2. Start the traversal
    for(int i =0; i< SIZE; i++)
    {
        // 3. Compare the key with each element
        comparisons++; // 4
        if(key == arr[i])  
        {
            //4. if the key is matching, return the corresponding index
            return i; 
        }
    }
    return -1; // key not found. 
}