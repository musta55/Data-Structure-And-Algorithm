#include<bits/stdc++.h>
float coin[100];
using namespace std;
int main()
{
       freopen("b.txt","r",stdin);
    int n,num=1;
    float sum;
  //  cout<<"Enter sum:";
    cin>>sum;
 //   cout<<"Enter number of coins:";
    cin>>n;
//    cout<<"Enter coins:";
        for(int i=0;i<n;i++)
    {
        cin>>coin[i];
    }
    sort(coin,coin+n);
   for(int i=0;i<n;i++)cout<<coin[i]<<endl;
          int j=n-1;
  while(sum>0.000011)
  {
     if(sum>=coin[j])
     {

        cout<<"sum="<<sum <<" ";
             sum-=coin[j];
            cout<<coin[j]  <<"  ";
              num++;
     }
    else if(sum<coin[j])
     {
  //  cout<<coin[j]  <<"  ";
                 j--;
         if(j<0)break;

     }
  }
  cout<<num<<endl;
}
