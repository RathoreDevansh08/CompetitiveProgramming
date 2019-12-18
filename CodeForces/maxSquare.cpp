#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int a[1005];
int t,m,n;

void read()
{
	cin>>n;
	
	for(int i = 0;i < n;i++)
		cin>>a[i];
	
	sort(a, a + n);
	reverse(a, a + n);
}

void solve()
{
	int ans = 0;
	for(int i = 0;i < n;i++)
	{
		ans = max(ans, min(a[i], i + 1));
	}
	cout<<ans<<"\n";
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--)
	{
		read();
		solve();
	}	
	
	return 0;
}
