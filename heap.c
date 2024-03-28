#include <stdio.h>

void swap(int *num1,int *num2)
{
    int temp;
    temp=*num1;
    *num1=*num2;
    *num2=temp;
}

void heapify (int arr[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n&&arr[left]>arr[largest])
    {
        largest=left;
    }
    if(right<n&&arr[right]>arr[largest])
    {
        largest=right;
    }
    if(largest!=i)
    {
        swap(&arr[i],&arr[largest]);
        heapify(arr,n,largest);
    }
}

void heapsort(int arr[],int n)
{
    int i;

    for(i=n/2-1;i>=0;i--)
    {
        heapify(arr,n,i);
    }
    for(i=n-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void printarray(int arr[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("%d\t",arr[i]);
    }
}

void main()
{
    int arr[]={23,10,4,44,19};

    heapsort(arr,5);
    printarray(arr,5);
}
