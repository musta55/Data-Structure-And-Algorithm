#include<bits/stdc++.h>
using namespace std;
int max=0,cost[100],weight[100],n;
float ratio[100];
int MaxIndex(){
    int index=0,i;
    float max=0;
    for(i=0;i<n;i++)
    {
        if(ratio[i]>max)
        {
            max=ratio[i];
            index=i;
        }

    }
    ratio[index]=-1;
    return index;
}

int main()
{
      freopen("b.txt","r",stdin);
    int ind;
    float total=0,w,capacity;
    cout<<"Enter number of object & total weight:"<<endl;
    cin>>n>>capacity;
    w=capacity;
    for(int i=0;i<n;i++)
    {
        cin>>cost[i]>>weight[i];
        if(weight[i]!=0)
        ratio[i]=(cost[i]/weight[i]);
    }
        while(1)
        {
            if(w<=0)break;
            ind=MaxIndex();
      //  cout<<ind<<endl;
          if(weight[ind]>w)
             {
                 total+=(w/weight[ind])*cost[ind];
                    w=0;
          break;
             }

            w=w-weight[ind];
        //    cout<<w<<endl;
           total+=cost[ind];

        }
        cout<<"Total cost is "<<total<<endl;

}

