
#include <stdio.h>
#define MAX 100
void merge(int datalist[],int p,int q,int r)
{
int n1=q-p+1;
int n2=r-q;
int l[n1],m[n2];
int i,j,k;
 for(i=0;i<n1;++i)
 {
 l[i]=datalist[p+i];
 }

 for(j=0;j<n2;j++)
 {
 m[j]=datalist[q+1+j];
 }

 i=0,j=0,k=p;

 while(i<n1&&j<n2)
 {
 if(l[i]<=m[j])
 {
 datalist[k]=l[i];
 i++;
 }
 else
 {
 datalist[k]=m[j];
 i++;
 }
 k++;
 }

 while(i<n1)
 {
 datalist[k]=l[i];
 i++;
 k++;
 }

 while(j<n2)
 {
 datalist[k]=m[j];
 j++;
 k++;
 }
}

 void mergesort(int datalist[],int l,int r)
 {
 if(l<r)
 {
 int m=l+(r-l)/2;
 mergesort(datalist,l,m);
 mergesort(datalist,m+1,r);
 merge(datalist,l,m,r);
 }
 }

 void printarray(int datalist[],int size)
 {
     printf("\n ascending order:=");
 for(int i=0;i<size;++i)
 {
 printf("%d\t",datalist[i]);
 }
 }

 int main()
 {
 int datalist[MAX];
 int index,size;

 printf("\n enter the size of the datalist:=");
 scanf("%d",&size);

 printf("\n enter %d elements of the datalist=",size);
 for(index=0;index<size;++index)
 {
 scanf("%d",&datalist[index]);
 }
 mergesort(datalist,0,size-1);
 printarray(datalist,size);
 }

