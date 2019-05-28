#include<bits/stdc++.h>

using namespace std;

int t,n,mx;
long int a,b;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		map<long int,int>mp;
		map<long int,int>::iterator it, it2;
		
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a>>b;
			mp[a]+=1;mp[b]-=1;
		}
		
		it=mp.begin();it2=it;it2++;
		mx=it->second;
		while(it2!=mp.end())
		{
			it2->second+=it->second;
			mx=max(mx,it2->second);
			it=it2;it2++;
		}
		cout<<mx<<"\n";
	}
	return 0;
}
