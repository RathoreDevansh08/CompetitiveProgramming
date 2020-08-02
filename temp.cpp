#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;++i)
#define frn(i,a,b) for(int i=a;i>=b;--i)
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>n;
	int a[n];
	int s=0;
	fr(i,0,n-1) {cin>>a[i];s+=a[i];}

	m = s/n;


	cout<<s/n;
	return 0;
}
