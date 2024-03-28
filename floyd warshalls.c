#include <stdio.h>
#define nv 4
#define INF 999

void printmatrix(int mmatrix[][nv]);

void floydwarshall(int graph[][nv])
{
    int matrix[nv][nv],i,j,k;

    for(i=0;i<nv;i++)
    {
        for(j=0;j<nv;j++)
        {
            matrix[i][j]=graph[i][j];
        }
    }

for(k=0;k<nv;k++)
{
    for(i=0;i<nv;i++)
    {
        for(j=0;j<nv;j++)
        {
            if(matrix[i][k]+matrix[k][j]<matrix[i][j])
            {
                matrix[i][j]=matrix[i][k]+matrix[k][j];
            }
        }
    }
}
}

void printmatrix(int matrix[][nv])
{
    for(int i=0;i<nv;i++)
    {
        for(int j=0;j<nv;j++)
        {
            if(matrix[i][j]==INF)
            {
                printf("%4s","INF");
            }
            else
            {
                printf("%4d",matrix[i][j]);
            }
        }
        printf("\n");
    }
}

int main()
{
    int graph[nv][nv]={{0,3,INF,5};
                      {2,0,INF,4};
                      {INF,1,0,INF};
                      {INF,INF,2,0}};

    floydwarshall(graph);
}
