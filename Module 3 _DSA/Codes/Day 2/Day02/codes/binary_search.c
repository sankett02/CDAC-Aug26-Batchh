#include<stdio.h>
#define SIZE 9

int binary_search(int arr[SIZE],int key);
int main()
{
    int arr[SIZE] = {11,22,33,44,55,66,77,88,99};
    int key ;
    printf("Enter the key to search :");
    scanf("%d",&key);

    int index = binary_search(arr,key);
    if(index == -1)
        printf("Key not found !");
    else
        printf("Key found at index %d\n",index);
    return 0;
}

int binary_search(int arr[SIZE],int key)
{
    int left = 0,right = SIZE-1, mid;
   while(left <= right)
   { 
        mid = (left+right)/2;
        if(key == arr[mid])
        {
            return mid; // return the corresponding index.
        }
        if(key < arr[mid])
        {
            //continue the search in the left sub-array.
            right = mid-1;
        }
        else
        {
            // //continue the search in the right sub-array.
            left = mid+1;
        }
   }
   return -1; // key not found.

}