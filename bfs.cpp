#include <stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2
int G[100][100];
int color[100],d[100],prev[100],q[100];
int front=0, rear=0;

void BFS(int s, int n)
{
    int u;
    for(int i=0;i<n;i++)
    {
        color[i]=WHITE;
        d[i]=-1;
        prev[i]=-1;
    }
    color[s]=GRAY;
    d[s]=0;
    prev[s]=0;

    q[rear++]=s;
    while(front!=rear)      //Exploring
    {
        u= q[front++];
        for(int v=0;v<n;v++)
        {
            if(G[u][v]==1)      //Finding adjacent nodes
               {                     //Visiting from graph
                if(color[v]==WHITE)
                    {
                        color[v]=GRAY;
                        d[v]=d[u]+1;
                        prev[v]=u;
                        q[rear++]=v;
                    }
               }
        }
        color[u]=BLACK;
    }
}


void print_path(int s, int dest)
{
    if(s==dest)
    {
        printf("%d->",s);
    }
    else if(d[dest]==-1)
    {
        printf("No path");
    }
    else
    {
        print_path(s,prev[dest]);
        printf("%d->",dest);
    }
}

int main()
{
    int n,e,u,v,s;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
    printf("Enter graph source: ");
    scanf("%d",&s);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        G[v][u]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    BFS(s,n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",color[i]);
    }

    printf("\n");

    for(int i=0;i<n;i++)
    {
        printf("%d ",d[i]);
    }

    printf("\n");

    print_path(s,0);


    return 0;
}
