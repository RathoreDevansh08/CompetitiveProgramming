#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int mem[100005], pok[]={0,1,2}, sz[]={1,2,2};
int dp(int m)
{
	if(m<0) return 0;
	if(m==0) return 1;
	long int k=0;
	if(mem[m]==-1)
	{
		for(auto e:pok)
		{
			k+=dp(m-sz[e]);
		}
		mem[m]=k%inf;
	}
	return mem[m];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	memset(mem,-1,sizeof mem);
	n=100000;
	b=dp(n);
	while(t--)
	{
		cin>>n;
		cout<<mem[n]<<"\n";
	}
	return 0;
}
