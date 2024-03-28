#include <stdio.h>
void main()
{
int datalist1[]={16,22,96,108,120};
int datalist2[]={4,10,44,124,190};
int merge[10];
int fp,sp,mp;

for(fp=0,sp=0,mp=0; ; )
{
if(datalist1[fp]<datalist2[sp])
{
merge[mp]=datalist1[fp];
mp++;
fp++;
}
else
if(datalist2[sp]<datalist1[fp])
{
merge[mp++]=datalist2[sp++];
}

if(fp==5||sp==5)
{
break;
}
}

for( ;fp<5;++fp,++mp)
{
merge[mp]=datalist1[fp];
}
for( ;sp<5; )
{
merge[mp++]=datalist2[sp++];
}

printf("\n merge list:=");
for(mp=0;mp<10;++mp)
{
    printf("%d\t",merge[mp]);
}
}
