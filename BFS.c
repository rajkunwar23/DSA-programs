# include <stdio.h>

int n,i,j;
int visited[10];
int queue[10];
int front =-1;rear=-1;
int adj[10][10];

void bfs(int v)
{
    for(i=1;i<n;i++)
    {
        if(adj[v][i]&&!visited[i])
        {
            queue[++rear]=i;
            if(front<=rear)
            {
                visited[queue[front]];
                bfs(queue[front++]);
            }
        }
    }
}

void main()
{
    int sv,i,v;

    printf("\n enter no. of vertices:=");
    scanf("%d",&v);

    for(i=0;i<v;i++)
    {
        visited[i]=0;
        queue[i]=0;
    }
    printf("\n enter the starting vertex:=");
    scanf("%d",&sv);
    bfs(sv);
    printf("\n print the nodes which are reachable:=");
    for(i=0;i<v;i++)
    {
        if(visited[i])
        {
            printf("%d",i);
        }
        else
        {
            printf("\n bfs is not possible");
        }
    }
}
