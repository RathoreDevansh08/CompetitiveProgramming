#include<bits/stdc++.h>
using namespace std;

#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
ll t,m,n,a,b,f=0;

ll gcd(ll a, ll b)
{
	if(b==0) return a;
	return gcd(b, a%b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	set<ll>fac;

	fr(i,2,sqrt(n))
	{
		if(n % i == 0) fac.insert(i), fac.insert(n/i);
	}
	
	//if(n==2) cout<<"2\n";
	if(fac.size() == 0) cout<<n<<"\n";
	else
	{
		b = *fac.begin();
		
		for(auto e:fac)
		{
			if(gcd(e, b) == 1)
			{ 
				cout<<1<<"\n";
				return 0;
			}
		}
		
		cout<<b<<"\n";
	}	
		
	return 0;
}
