#include <stdio.h>

int a[20][20],reach[20],n;

void dfs(int v)
{
    int i;
    reach[v]=1;

    for(i=1;i<n;i++)
    {
        if(a[v][i]&&!reach[i])
        {
            printf("%d->%d",v,i);
            dfs(i);
        }
    }
}

void main()
{
    int i,j,n,count=0;

    printf("\n enter the no. of vertices:=");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        reach[i]=0;
        for(j=1;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    printf("\n enter the adjacency matrix:=");
    for(i=1;i<n;i++)
    {
        for(j=1;j<n;j++)
        {
            scanf("%d",&a[i][j]);
        }
        dfs(1);
        printf("\n");
    }

    for(i=1;i<=n;i++)
    {
        if(reach[i])
        {
            count++;
        }
        if(count==n)
        {
            printf("\n graph is connected");
        }
        else
            {
                printf("\n graph is not connected");
            }
    }


}
