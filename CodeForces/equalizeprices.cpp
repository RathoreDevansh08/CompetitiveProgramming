#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int q,t,m,n,a,b,f=0;
ll k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>q;
	while(q--)
	{
		cin>>n>>k;
		ll ar[n], mn=LLONG_MAX, mx=LLONG_MIN;
		fr(i,0,n-1)
		{
			cin>>ar[i];
			mn=min(mn,ar[i]);
			mx=max(mx,ar[i]);
		}
		if(mn+k>=mx-k)
		{
			cout<<mn+k<<"\n";
		}
		else cout<<"-1\n";
	}
	return 0;
}
