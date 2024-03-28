#include <stdio.h>
#define MAX 100
void selectionsort(int[],int);
void main()
{
int datalist[MAX];
int size,index;

printf("\n enter the size of the datalist:=");
scanf("%d",&size);

printf("\n enter the %d elements of the datalist:=",size);
for(index=0;index<size;++index)
{
scanf("%d",&datalist[index]);
}

selectionsort(datalist,size);
}

void selectionsort(int datalist[],int size)
{
int change,fixed,temp;

for(fixed=0;fixed<size-1;++fixed)
{
for(change=fixed+1;change<size;++change)
{
if(datalist[fixed]>datalist[change])
{
temp=datalist[fixed];
datalist[fixed]=datalist[change];
datalist[change]=temp;
}
}
}

printf("\n datalist in ascending order:=\n");
for(change=0;change<size;++change)
{
printf("%d\t",datalist[change]);
}
for(fixed=0;fixed<size-1;++fixed)
{
for(change=fixed+1;change<size;++change)
{
if(datalist[fixed]<datalist[change])
{
temp=datalist[fixed];
datalist[fixed]=datalist[change];
datalist[change]=temp;
}
}
}

printf("\n datalist in descending order:=\n");
for(change=0;change<size;++change)
{
printf("%d\t",datalist[change]);
}
}
