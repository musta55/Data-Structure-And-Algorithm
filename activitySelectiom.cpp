#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    printf("How many activities\n");
    cin>>n;
    int start[n],finish[n],i,j,t;

    printf("Enter starting and finishing time\n");
    for(i=0; i<n; i++)
    {
        cin>>start[i]>>finish[i];
    }
    sort(finish,finish+n-1);
    i=0;
   cout<<i<<" ";

    for(j=1;j<n;j++)
    {
        if(start[j]>=finish[i])
        {
            cout<<j <<" ";
            i=j;
        }
    }
}
