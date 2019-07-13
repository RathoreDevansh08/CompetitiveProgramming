#include<bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;

string st;
ll t,m,n,k,a,b,f=0,j,ans;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n>>m>>k;
	vector<ll>wp(m);
	fr(i,0,m-1) cin>>wp[i];
	
	ans=0;
	j=0;f=0;
	while(j<m)
	{
		if( (wp[j]-f)%k!=0 )a = (wp[j]-f)/k + 1;
		else a= ((wp[j]-f)/k);
		ll o=0;
		while(j<m) 
		{
			if( (wp[j]-f)%k!=0 ) b = (wp[j]-f)/k + 1;
			else b=(ll)((wp[j]-f)/k);
			//cout<<b<<"-";
			if(b==a) {j++;o++;}
			else break;
		}
		f+=o;
		ans+=1;
		//if(o==0)break;
	}
	cout<<ans<<"\n";
	return 0;
}
