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
ll t,m,n,a,b,k,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		ll a[n], sm[n];
		cin>>a[0];sm[0]=a[0];
		fr(i,1,n-1) {cin>>a[i];sm[i]=sm[i-1]+a[i];}
		
		ll j=0, fl=0, r=0;
		vector<ll>ind;
		while(j<n && k!=0)
		{
			if((sm[j]-r)%2!=0)
			{
				k--;r=sm[j];
				ind.pb(j+1);
			}
			j++;
		}
		
		if(k==0 && j<n)
		{
			if((sm[n-1]-r)%2==0)
			{
				cout<<"YES\n";
				fr(i,0,ind.size()-1) {if(i!=ind.size()-1)cout<<ind[i]<<" ";}
				cout<<n;
				cout<<"\n";
			}
			else cout<<"NO\n";
		}
		else if(k!=0) cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			fr(i,0,ind.size()-1) {if(i!=ind.size()-1)cout<<ind[i]<<" ";}
			cout<<n;
			cout<<"\n";
		}
	}
	return 0;
}
