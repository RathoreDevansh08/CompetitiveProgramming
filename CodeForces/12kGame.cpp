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
int t,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		
		int ans=0;
		if(m%3!=0 && n%3==0) ans=1;
		else if(m%3!=0) ans=0;
		else
		{
			b=(n%(m+1));
			if(b%3==0 && m!=b) ans=1;
		}
		
		if(ans) cout<<"Bob\n";
		else cout<<"Alice\n";
	}
	return 0;
}
