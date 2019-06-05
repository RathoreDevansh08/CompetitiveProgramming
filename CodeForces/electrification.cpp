#include<iostream>
#include<vector>
using namespace std;

#define inf 1000000007
#define pb push_back
#define for(i,a,b) for(long int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

long int t,m,n,k,a,b,f=0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long int a[n];
		for(i,0,n-1) cin>>a[i];
		if(n==1 || k==0) {cout<<a[0]<<"\n";}
		else
		{
			long int ab=1000000000000,j=0;
			for(i,0,n-k-1)
			{
				if((a[k+i]-a[i])<ab)
				{
					ab=a[k+i]-a[i];
					j=i;
				}
			}
			if((a[k+j]+a[j])%2==0)cout<<(a[k+j]+a[j])/2<<"\n";
			else cout<<(a[k+j]+a[j])/2<<"\n";
		}
	}
	return 0;
}
