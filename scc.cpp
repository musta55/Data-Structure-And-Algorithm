#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2

int G[100][100],G2[100][100];
int color[100], d[100], f[100], prev[100],scc[100];
int time=0,count=0;

int maximum(int n)
{
    int max=0,store;
    for(int i=0;i<n;i++)
    {
        if(f[i]>max)
        {
            max=f[i];
            store=i;

        }
    }
    f[store]=-1;
    return store;
}

void DFS_visit(int u, int n) {
    time++;
    d[u]=time;
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
        if(G[u][v]==1) {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visit(v,n);
            }
        }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;

}

void DFS_visitScc(int u, int n,int count) {
    color[u]=GRAY;
    for(int v=0;v<n;v++) {
            if(G2[u][v]==1)
            {
            if(color[v]==WHITE)
            {
                prev[v]=u;
                DFS_visitScc(v,n,count);
            }
            }
    }
    color[u]=BLACK;
    scc[u]=count;
    scc[u]=-1;

}

void DFS(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    for(int u=0;u<n;u++) {
        if(color[u]==WHITE)
            DFS_visit(u,n);
    }
}

void DFSScc(int n)
{
    for(int i=0;i<n;i++) {
        color[i]=WHITE;
        prev[i]=-1;
    }

    printf("we\n");
    for(int u=0;u<n;u++) {
        int node=maximum(n);
        printf("%d ",node);
        if(color[node]==WHITE)
            DFS_visitScc(node,n,count++);
    }
}


int main() {
    int n, e, u, v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);
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
        G2[v][u]=1;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(n);

    for(int i=0;i<n;i++)
    {
        printf("%d ",f[i]);
    }

    DFSScc(n);
printf("Why man\n");
    for(int i=0;i<count;i++){
        for(int j=0;j<n;j++)
        {
            if(scc[j]==i)printf("%d ",j);
        }
        printf("\n");
    }
    return 0;
}
