#include<bits/stdc++.h>

using namespace std;

const long long int N = 123456;
long long int dp[N][4];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long int n,m;
	cin >> n >> m;
	
	long long int a[n],b[n];
	for (long long int i = 0; i < n;i++)cin >> a[i];
	for (long long int i = 0; i < n;i++)cin >> b[i];
	
	long long int pos1 = 0, pos2 = 0;
	for (long long int j = 1; j <= n;j++)
	{
		pos1++ %2 == 0 ? dp[j][0] = dp[j-1][0] + a[j - 1]: dp[j][0] = dp[j-1][0] + b[j - 1];
		pos2++ %2 == 0 ? dp[j][1] = dp[j-1][1] + b[j - 1]: dp[j][1] = dp[j-1][1] + a[j - 1];
	}
	
	for (long long int i = 0; i < m;i++)
	{
		long long int x, l, r;
		cin >> x >> l >> r;
		if(x == 1) l % 2 == 1 ? cout << dp[r][0] - dp[l-1][0] << endl: cout << dp[r][1] - dp[l-1][1] << endl;
		if(x == 2) l % 2 == 1 ? cout << dp[r][1] - dp[l-1][1] << endl: cout << dp[r][0] - dp[l-1][0] << endl;
	}
	return 0;
}
