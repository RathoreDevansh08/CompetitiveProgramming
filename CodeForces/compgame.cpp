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
ll t,k,k0,m,n,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>k>>n>>a>>b;
		f=0;k0=k;
		if(n*b>=k) {cout<<"-1\n";continue;}
		
		
		ll r=0, wc=0;
		//if(k>a)
		//{
			if(k%a==0) r=k/a-1;
			else r=k/a;
			//k=k-r*a;
			wc=r;
		//}
		if(wc>=n) {cout<<n<<"\n";f=1;}
		else
		{
			m=(k-n*b)/(a-b);
			if(!m) cout<<0<<"\n";
			else
			{
				if(!((k-a*m)%b)) r=(k-a*m)/b-1;
				else r=(k-a*m)/b;
				
				if(r<(n-m)) cout<<m-1<<"\n";
				else cout<<m<<"\n";
			}
		}
	}
	return 0;
}
