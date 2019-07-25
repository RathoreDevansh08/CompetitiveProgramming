#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll p[n][2],d[n][4],mi[n][2],ma[n][2];
        for(i=0;i<n;i++)
        {
            cin>>p[i][0]>>p[i][1]>>d[i][0]>>d[i][1]>>d[i][2]>>d[i][3];
            mi[i][0]=p[i][0];mi[i][1]=p[i][1];
            ma[i][0]=p[i][0];ma[i][1]=p[i][1];
        }
        if(n==1)
         {cout<<"1 "<<p[n-1][0]<<" "<<p[n-1][1]<<"\n";}
        else
         {
            for(i=0;i<n;i++)
            {
                if(d[i][0]==1)
                 mi[i][0]=-100000;
                if(d[i][1]==1)
                 ma[i][1]=100000;
                if(d[i][2]==1)
                 ma[i][0]=100000;
                if(d[i][3]==1)
                 mi[i][1]=-100000; 
            }
            ll x1=-100000,y1=-100000,x2=100000,y2=100000;
            for(i=0;i<n;i++)
            {
               x1=max(x1,mi[i][0]);
               x2=min(x2,ma[i][0]);
               y1=max(x1,mi[i][1]);
               y2=min(x1,ma[i][1]);
            }
            if(x1>x2||y1>y2)
             cout<<"0\n";
            else
             cout<<"1 "<<x1<<" "<<y1<<"\n";
         }
    }
}
