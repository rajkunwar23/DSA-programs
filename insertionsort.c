#include <stdio.h>
#define MAX 100
void insertionsort(int[],int);
int main()
{
int datalist[MAX];
int size,i;

printf("\n enter the size of the datalist:=");
scanf("%d",&size);

printf("\n enter %d elements of the datalist:=",size);
for(i=0;i<size;++i)
{
scanf("%d",&datalist[i]);
}

insertionsort(datalist,size);
}

void insertionsort(int datalist[],int size)
{
int step,i,key;

for(step=1;step<size;++step)
{
key=datalist[step];
i=step-1;

while(key<datalist[i]&&i>=0)
{
datalist[i+1]=datalist[i];
--i;
}
datalist[i+1]=key;
}

printf("\n ascending order of the datalist:=");
for(i=0;i<size;++i)
{
printf("%d\t",datalist[i]);
}
}
