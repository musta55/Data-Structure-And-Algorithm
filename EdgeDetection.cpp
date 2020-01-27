#include<stdio.h>
#define WHITE 0
#define GRAY 1
#define BLACK 2



int G[30][30];
int color[30], d[30], f[30], prev[30];
int time=0;

void print_path(int s, int v) {
    if(s==v) {
        printf("%d->",s);
    }
    else if(prev[v]==-1) {
        printf("No Path");
    }
    else {
        print_path(s,prev[v]);
        printf("%d->",v);
    }
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
                printf("%d %d is a tree edge\n",u,v);
                DFS_visit(v,30);
            }
            else if(color[v]==GRAY&&color[u]==GRAY)
            {
                printf("%d %d is a back edge\n",u,v);
            }

            else if(color[v]==BLACK)
                {
                    if(d[u]<d[v])
                    {
                    printf("%d %d is forward edge\n",u,v);
                    }

                    else
                    {
                        printf("%d %d is a cross edge\n",u,v);
                    }

                }


            }
    }
    time++;
    f[u]=time;
    color[u]=BLACK;
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


int main() {

    int n, e, u, v;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    printf("Enter number of edges: ");
    scanf("%d",&e);


    for(int i=0;i<30;i++)
    {
        for(int j=0;j<30;j++)
        {
            G[i][j]=0;
        }
    }

    for(int i=0;i<e;i++)
    {
        printf("Enter edges:");
        scanf("%d %d",&u,&v);
        G[u][v]=1;
    }

    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            printf("%-4d",G[i][j]);
        }
        printf("\n");
    }

    DFS(20);

    for(int i=0;i<20;i++)
    {
        printf("%d ",color[i]);
    }


    printf("\n");
    for(int i=0;i<20;i++)
    {
        printf("%d ",f[i]);
    }





    return 0;
}
