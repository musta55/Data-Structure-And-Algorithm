#include<stdio.h>

int G[9][9];
int color[9], d[9], f[9], prev[9],queue[9],front=0,rear=0,order[9];
int time=0;

int main() {

    int n, e, u, v,temp=0,i,count=0,t;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter number of edges: ");
    scanf("%d",&e);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            G[i][j]=0;
        }
    }

    for(i=0;i<n;i++)
    {
        d[i]=0;
    }


    for(int i=0;i<e;i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
        d[v]++;

    }


    for(u=0;u<n;u++)
    {
        if(d[u]==0)
        {
            rear++;
            queue[rear]=u;
        }
    }


    u=0;

    while(front!=rear)
    {
        t=queue[front];
        front++;
        count++;
        order[u]=t;
        u++;
        if(d[t]==0)
        {

            for(v=0;v<n;v++)
            {
                if(G[t][v]==1)
                {
                   d[v]--;
                   if(d[v]==0)
                   {
                       rear++;
                       queue[rear]=v;
                   }
                }
            }
        }

    }


    for(i=0;i<n;i++)
    {
        printf("%d ",order[i]);
    }




    return 0;
}
