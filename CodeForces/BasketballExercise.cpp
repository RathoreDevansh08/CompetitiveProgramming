#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(long long int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<ll> vi;

string st;
ll t,m,n,f=0;
vi a(100001), b(100001);
ll mem[100001][3];

ll dp(ll ab, ll k)
{
	if(ab>=n) return 0;
	if(mem[ab][k]) return mem[ab][k];
	
	ll h, h1, h2, h3;
	if(k==2)
	{
		h1=mem[ab+1][0]?mem[ab+1][0]:dp(ab+1, 0);
		h2=mem[ab+1][1]?mem[ab+1][1]:dp(ab+1, 1);
		h3=mem[ab+1][k]?mem[ab+1][k]:dp(ab+1, k);
		h = a[ab]+h1 > b[ab]+h2 ? a[ab]+h1 : b[ab]+h2;
		h = h>h3 ? h : h3;
	}
	else if(k==0)
	{
		h1=mem[ab+1][k]?mem[ab+1][k]:dp(ab+1, k);
		h2=mem[ab+1][1]?mem[ab+1][1]:dp(ab+1, 1);
		h = b[ab]+h2 > h1 ? b[ab]+h2 : h1;
	}
	else 
	{
		h1=mem[ab+1][0]?mem[ab+1][0]:dp(ab+1, 0);
		h2=mem[ab+1][k]?mem[ab+1][k]:dp(ab+1, k);
		h = a[ab]+h1 > h2 ? a[ab]+h1 : h2;
	}
	mem[ab][k]=h;
	return h;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	
	fr(i,0,n-1) cin>>a[i];
	fr(i,0,n-1) cin>>b[i];
	
	cout<<dp(0,2)<<"\n";
	return 0;
}
