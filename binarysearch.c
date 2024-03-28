#include <stdio.h>
#define MAX 100
void binarysearch(int[],int,int,int);
int main()
{
int datalist[]={10,20,30,40,50};
int search;

printf("\n enter the search value:=");
scanf("%d",&search);

binarysearch(datalist,0,4,search);
}

void binarysearch(int datalist[],int start,int end,int search)
{
    char flag='n';
    int mid;

    while(start<=end)
    {
        mid=(start+end)/2;
        if(datalist[mid]==search)
        {
            flag='y';
            break;
        }
        else if(datalist[mid]<search)
        {
            start=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }

    if(flag=='y')
    {
        printf("\n value found");
    }
    else
    {
        printf("\n value not found");
    }
}
