#include<iostream>
#include<map>
#include<utility>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
	int n;
	cin>>n;
	
	long int a,b,k=0,ka,kb,s,p=0,z,z2;
	map<long int,long int>mp,mp2;
	map<long int,long int>::iterator it;
	vector<long int>vis(n+1),nxt(n+1),cnt(n+1);
		
	for(int i=0;i<n+1;i++){vis[i]=-1;nxt[i]=-1;cnt[i]=0;}
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		
		if(mp.find(a)==mp.end())mp.insert(pair<long int,long int>(a,k++));
		if(mp.find(b)==mp.end())mp.insert(pair<long int,long int>(b,k++));
		ka=mp[a];kb=mp[b];
		
		if(nxt[ka]!=-1 && nxt[kb]!=-1)
		{
			long int y=ka;z=nxt[y];
			while(z!=-1)
			{
				z2=nxt[z];
				//z=nxt[y];
				nxt[z]=y;
				y=z;
				z=z2;
			}
			nxt[ka]=kb;
		}
		else if(nxt[ka]==-1 && vis[kb]==-1)nxt[ka]=kb;
		else if(vis[kb]!=-1 && nxt[kb]!=-1)nxt[ka]=kb;
		else nxt[kb]=ka;
		vis[ka]=1;vis[kb]=1;cnt[ka]++;cnt[kb]++;
	}
	for(it=mp.begin();it!=mp.end();++it)
	{
		mp2.insert(pair<long int,long int>(it->second,it->first));
		p=it->second;
		if(cnt[p]==1 && nxt[p]!=-1)s=p;
	}
	p=0;
	while(p!=(n+1))
	{
		cout<<mp2[s]<<" ";
		s=nxt[s];
		p++;
	}
	cout<<"\n";
	return 0;
}
