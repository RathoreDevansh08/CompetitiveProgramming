#include<bits/stdc++.h>

using namespace std;
#define inf 1000000007

int t;long long int n,k;
map<long long int, long long int> mem;
map<long long int, long long int>::iterator it;
long long int dp(long long int n)
{
	if(n==1) return 2;
	else if(n==0) return 1;
	else if(n<0) return 0;
	it=mem.lower_bound(n);
	if(it==mem.end() || it->first!=n) mem[n]=(dp(n-1)%inf+dp(n-2)%inf)%inf;
	return mem[n];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	mem[0]=1;mem[1]=2;
	k=mem[1000000000000000001];
	while(t--)
	{
		cin>>n;
		cout<<dp(n)<<"\n";
	}
	return 0;
}
