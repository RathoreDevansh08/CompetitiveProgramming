#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;++i) 
#define frn(i,a,b) for(int i=a;i>=b;--i) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		int la=0, lb=0, ra=0, rb=0, lp=n-1, rp=n, ar[2*n];
		
		a=0;b=0;
		fr(i,0,n-1)
		{
			cin>>ar[i];
			if(ar[i]==1) a++, la++;
			else b++, lb++;
		}
		
		fr(i,n,2*n-1)
		{
			cin>>ar[i];
			if(ar[i]==1) a++, ra++;
			else b++, rb++;
		}
		
		int ans=0;
		while(a!=b)
		{
			if(a>b)
			{
				if(ar[lp]==ar[rp] && ar[lp]==1)
				{
					ar[lp]=0;
					if(lp) lp--;
					a--;la--;ans++;
				}
				else if(ar[lp]==ar[rp] && ar[lp]==2)
				{
					if(la>=ra)
					{
						ar[lp]=0;
						if(lp) lp--;
						b--;lb--;ans++;
					}
					else
					{
						ar[rp]=0;
						if(rp!=2*n-1) rp++;
						b--;rb--;ans++;
					}
				}
				else if(ar[lp]==1)
				{
					ar[lp]=0;
					if(lp) lp--;
					a--;la--;ans++;
				}
				else 
				{
					ar[rp]=0;
					if(rp!=2*n-1) rp++;
					a--;ra--;ans++;
				}
			}
			else
			{
				if(ar[lp]==ar[rp] && ar[lp]==2)
				{
					ar[lp]=0;
					if(lp) lp--;
					b--;lb--;ans++;
				}
				else if(ar[lp]==ar[rp] && ar[lp]==1)
				{
					if(lb>=rb)
					{
						ar[lp]=0;
						if(lp) lp--;
						a--;la--;ans++;
					}
					else
					{
						ar[rp]=0;
						if(rp!=2*n-1) rp++;
						a--;ra--;ans++;
					}
				}
				else if(ar[lp]==2)
				{
					ar[lp]=0;
					if(lp) lp--;
					b--;lb--;ans++;
				}
				else 
				{
					ar[rp]=0;
					if(rp!=2*n-1) rp++;
					b--;rb--;ans++;
				}
			}
			
		}
		cout<<ans<<"\n";
	}
	return 0;
}
