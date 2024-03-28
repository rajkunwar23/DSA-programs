#include <stdio.h>
#define v 4

void init(int arr[][v])
{
    int i,j;
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            arr[i][j]=0;
        }
    }
}

void addedge(int arr[][v],int i,int j)
{
    arr[i][j]=1;
    arr[j][i]=1;
}

void printadjmatrix(int arr[][v])
{
    int i,j;

    for(i=0;i<v;i++)
    {
        printf("%d\t",i);
        for(j=0;j<v;j++)
        {
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

}

int main()
{
    int adjmatrix[v][v];

    init(adjmatrix);
    addedge(adjmatrix,0,1);
    addedge(adjmatrix,0,2);
    addedge(adjmatrix,1,2);
    addedge(adjmatrix,2,0);
    addedge(adjmatrix,2,3);
    printadjmatrix(adjmatrix);

}
