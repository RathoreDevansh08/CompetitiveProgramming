#include<iostream>

using namespace std;
#define inf 10000000000000

int t,n,a[1000005];
long int sum,sum2,x=inf;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		for(int i=0;i<n;i++) {cin>>a[i];sum+=a[i];}
		
		x=inf;sum2=0;
		for(int i=0;i<n;i++)
		{
			sum2+=a[i];sum-=a[i];
			if(sum-sum2>=0) x=min(x,sum-sum2);
			else break;
		}
		if(x==inf) cout<<"-1\n";
		else cout<<x<<"\n";
	}
	return 0;
}
