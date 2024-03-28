# include <stdio.h>
#define MAX 100
void linearsearch(int[],int,int);
int main()
{
int datalist[MAX];
int size,i;
int search;

printf("\n enter the size of the datalist:=");
scanf("%d",&size);

printf("\n enter the %d elements of the datalist=",size);
for(i=0;i<size;++i)
{
scanf("%d",&datalist[i]);
}

printf("\n enter the search value:=");
scanf("%d",&search);

linearsearch(datalist,size,search);
}

void linearsearch(int datalist[],int size,int search)
{
int i;

for(i=0;i<size;++i)
{
if(datalist[i]==search)
{
    printf("\nvalue found");
break;
}

if(i!=size-1)
{
     printf("\n not found");
}
}


