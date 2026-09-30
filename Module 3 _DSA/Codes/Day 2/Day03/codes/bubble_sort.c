#include<stdio.h>
#define SIZE 6
void bubble_sort(int arr[SIZE]);
void efficient_bubble_sort(int arr[SIZE]);
void display(int arr[SIZE]);
int main()
{
    //int arr[SIZE] = {30,20,60,50,10,40};
    int arr[SIZE] = {11,22,33,44,55,66};
    printf("\n Before normal Sort :\n");
    display(arr);
    bubble_sort(arr);
    printf("\n After noraml sort :\n");
    display(arr);

    printf("\n\n\n Before Efficient Sort :\n");
    display(arr);
    efficient_bubble_sort(arr);
    printf("\n After efficient sort :\n");
    display(arr);

    return 0;
}

void bubble_sort(int arr[SIZE])
{
    int it =0, comp = 0;
    // iterations : n-1 : n--> SIZE :6
    for(int i = 0;i < SIZE-1; i++) //i : 4
    {
        it++;
        for(int pos = 0; pos <SIZE-1-i; pos++) // 0 to 0 : 
        {
            comp++;
            if(arr[pos] > arr[pos+1]) // if(arr[4] > arr[4+1])
            {
                // swap
                int temp = arr[pos];
                arr[pos] = arr[pos+1];
                arr[pos+1] = temp;
            }
        }

    }
    printf("\n iterations = %d cmparisons = %d\n",it,comp);

}


void efficient_bubble_sort(int arr[SIZE])
{
    int it =0, comp = 0,flag;
    // iterations : n-1 : n--> SIZE :6
    for(int i = 0;i < SIZE-1; i++) //i : 4
    {
        it++;
        flag = 0;
        for(int pos = 0; pos <SIZE-1-i; pos++) // 0 to 0 : 
        {
            comp++;
            if(arr[pos] > arr[pos+1]) // if(arr[4] > arr[4+1])
            {
                // swap
                int temp = arr[pos];
                arr[pos] = arr[pos+1];
                arr[pos+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }
    printf("\n iterations = %d cmparisons = %d\n",it,comp);

}




void display(int arr[SIZE])
{
    for(int i =0; i<SIZE; i++)
    {
        printf("%4d",arr[i]);
    }
}

/*
time complexity:
Best Case : if data is sorted : O(n)
worst Case : O(n^2)
Avg Case : O(n^2)


space complexity :
input space : O(n)
Aux space : O(1) constant

Total space comp : O(n)
space compleity : O(1)

*/