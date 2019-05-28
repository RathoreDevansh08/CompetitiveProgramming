#include<iostream>
#include<cstring>

using namespace std;
#define inf 1000000007

long long int m,n,c[1000002],dp[1000002]={0};
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>m>>n;
	for(int i=0;i<m;i++) cin>>c[i];
	
	dp[0]=1;
	//memset(dp,0,sizeof dp);
	for(int i=0;i<m;i++)
	{
		for(int j=c[i];j<=n;j++)
		{
			dp[j]+=dp[j-c[i]];
			dp[j]%=inf;
		}
	}	
	cout<<dp[n]<<"\n";
	return 0;
}
