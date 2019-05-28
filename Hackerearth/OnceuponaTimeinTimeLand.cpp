#include<iostream>
#include<cstring>

using namespace std;

int t,n,k;
long long int a[10001],mem[10001];
long long int dp(int i)
{
	if(i>=n) return 0;
	if(mem[i]==-1) mem[i]=max(a[i]+dp(i+k+1),dp(i+1));
	return mem[i];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		memset(mem,-1,sizeof mem);
		cin>>n>>k;
		for(int i=0;i<n;i++) cin>>a[i];
		cout<<dp(0)<<"\n";
	}
	return 0;
}
