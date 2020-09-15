#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
//#define fr(i,a,b) for(int i=a;i<=b;++i)
//#define frn(i,a,b) for(int i=a;i>=b;--i)
typedef long long int ll;
typedef vector<int> vi;

vi mm(200005);
long int d1=0, d2=0, d3=0;
long int rec(int i, int n, long int sm, vi c, int x)
{
	if(mm[i] != -1) return mm[i];

	if(i >= (n-1)) return c[n-1];

	if(i+1 < n) d1 = c[i+1] + rec(i+1,n,sm,c,x);
	else d1 = c[i+1] + rec(i+1,n,sm,c,x) - x*((i+1) - (n-1));
	if(i+2 < n) d2 = c[i+2] + rec(i+2,n,sm,c,x);
	else d2 = c[i+2] + rec(i+2,n,sm,c,x) - x*((i+2) - (n-1));
	if(i+3 < n) d3 = c[i+3] + rec(i+3,n,sm,c,x);
	else d3 = c[i+3] + rec(i+3,n,sm,c,x) - x*((i+3) - (n-1));

	if(d1 <= d2 && d1 <= d3)
	{
		mm[i] = d1;
	}
	else if(d2 <= d1 && d2 <= d3)
	{
		mm[i] = d2 + x;
	}
	else {
		mm[i] = d3 + 2*x;
	}
	sm += mm[i] + c[i];
	return sm;
}

string st;
int t,m,n,a,b,x,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n>>x;
	vi c;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		c.pb(a);
	}

	for(int i=0;i < 200005; i++)
	{
		mm[i]= -1;
	}
	mm[n-1] = c[n-1];

	cout<<rec(0, n, 0, c, x);
	//cout<<mm[0];
	return 0;
}
