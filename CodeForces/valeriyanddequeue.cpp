#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int n,a,b,q,f=0,mx=-1;
ll m,t;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>q;
	deque<int>d;
	int ar[n];
	vector<pair<int,int>>v;
	fr(i,0,n-1)
	{
		cin>>a;
		d.pb(a);
		if(mx<a) mx=a;
	}
	
	int x=d.front();d.pop_front();
	int y=d.front();d.pop_front();
	v.pb(mp(x,y));
	while(x!=mx)
	{
		if(x!=mx && x>=y)
		{
			d.push_front(x);d.pb(y);
		}
		else if(x!=mx)
		{
			d.push_front(y);d.pb(x);
		}
		x=d.front();d.pop_front();
		y=d.front();d.pop_front();
		v.pb(mp(x,y));
	}
	t=v.size();
	
	ar[0]=x;ar[1]=y;
	fr(i,2,n-1)
	{
		ar[i]=d.front();
		d.pop_front();
	}
	
	while(q--)
	{
		cin>>m;m--;
		if(m<t) cout<<v[m].first<<" "<<v[m].second<<"\n";
		else
		{
			m=((m-t+1)%(n-1)) + 1;
			cout<<mx<<" "<<ar[m]<<"\n";
		}
	}
	
	return 0;
}
