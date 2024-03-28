#include <stdio.h>

int arr[5]={1,2,3,4};
int index=-1;
void add_at_begin(int);
int main()
{
    int data;

    printf("\n enter the data:=");
    scanf("%d",&data);

    add_at_begin(data);
}

void add_at_begin(int data)
{
    int i;

    if(index==4)
    {
        puts("\n array is full");
    }
    else if(index==-1)
        {
            ++index;
            arr[index]=data;
        }
        for(i=index;i>=0;--i)
        {
            arr[i+1]=arr[i];
        }
        arr[i]=data;
        display();
}

void display(int data)
{
    int i;

    if(index==4)
    {
        puts("\n array is full");
    }
    else
    {
    for(i=0;i<=index;i++)
    {
        printf("%d\t",arr[i]);
    }
    }
}
