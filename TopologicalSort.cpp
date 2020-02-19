#include<bits/stdc++.h>

using namespace std;
int G[100][100];
int  order[100];
int d[100];
int main() {

    int n, e, u, v,temp=0,i,count=0,t;
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
            queue.push(u);
        }
    }


    u=0;

    while(queue.empty())
    {
        t=queue.pop();                   //dequeue
        count++;
        order[u++]=t;
        if(d[t]==0)
        {
            for(v=0;v<n;v++)
            {
                if(G[t][v]==1)
                {
                   d[v]--;
                   if(d[v]==0)
                   {
                       queue.push(v);     //enqueue
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
