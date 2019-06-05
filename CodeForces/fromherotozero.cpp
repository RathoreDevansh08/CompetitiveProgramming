#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define for(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

ll t,m,n,a,b,f=0;
ll k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		if(k>n || k==1) cout<<n<<"\n";
		else if(k==n) cout<<2<<"\n";
		else
		{
			f=0;
			while(n!=0)
			{
				if(n%k==0) {n=n/k;f++;}
				else
				{
					f+=n%k;
					n=n-(n%k);
				}
			}
			cout<<f<<"\n";
		}
	}
	return 0;
}
