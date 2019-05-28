#include<iostream>

using namespace std;

#define inf 1000000007

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n,mix,mx,miy,my,a,b,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		mix=inf;miy=inf;
		mx=-inf;my=-inf;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			if(a<mix)mix=a;
			if(a>mx)mx=a;
			if(b<miy)miy=b;
			if(b>my)my=b;
		}
		k=max(my-miy,mx-mix);
		cout<<k*k<<"\n";
	}
	
	return 0;
}	
