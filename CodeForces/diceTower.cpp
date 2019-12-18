#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,m,a,b,f=0;
ll n;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<=14) {cout<<"NO\n";continue;}
		
		n = 14 + n % 14;
		if(n>=15 && n<=20) cout<<"YES\n";
		else cout<<"NO\n";
		
	}
	return 0;
}
