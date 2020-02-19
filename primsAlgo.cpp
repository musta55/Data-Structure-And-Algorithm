#include<stdio.h>
int G[100][100]={0},cost[100],n,m,prev[100],visited[100];
void initializeSingleSource(int s)
{
    for(int i=0;i<n;i++)
    {
        cost[i]=10000;
        visited[i]=0;
        prev[i]=-1;
    }
    cost[s]=0;

}

int extractmin()
{
    int min=1000000,u;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && cost[i]<min)
        {
            min=cost[i];
            u=i;
        }

    }
    return u;
}

    void relax(int u,int v)
    {
        if(cost[v]>G[u][v] && visited[v]==0)
        {
            cost[v]=G[u][v];
            prev[v]=u;
        }

    }

void prim(int s)
{
    int u;
    initializeSingleSource(s);
    while(1)
    {
          u=extractmin();
    visited[u]=1;
    for(int v=0;v<n;v++)
    {
        if(G[u][v]!=0 )relax(u,v);
    }
    int i=0;
   for(;i<n;i++)
   {
       if(visited[i]==0)break;
   }
   if(i==n)break;

    }

}
int main()
{

        int u,v,w;
     freopen("mst.txt","r",stdin);
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            G[u][v]=w;
            G[v][u]=w;
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",G[i][j]);
            }
            printf("\n");
        }

        prim(1);
    int MST=0;
    for(int  i=0;i<n;i++)
    {
        MST+=cost[i];
       printf("\t%d ",prev[i]);
    }

    printf("\nTotal Cost = %d",MST);
    return 0;
}
