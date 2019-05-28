#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n,a,b,c;
	cin>>n;
	int G[n][n];
	int vis[n],nxt[n];
	long int ct=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			{G[i][j]=0;nxt[i]=-1;vis[i]=0;}
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c;
		a--;b--;
		G[a][b]=c;
		ct+=c;
		if(nxt[a]==-1 && vis[b]==0)nxt[a]=b;
		else if(vis[b]==1 && nxt[b]!=-1)nxt[a]=b;
		else nxt[b]=a;
		vis[a]=1;vis[b]=1;
	}
	long int cl=0,k=0,acl=0;
	while((cl+acl)!=ct)
	{
		if(G[k][nxt[k]]!=0)
		{
			cl+=G[k][nxt[k]];
		}
		else acl+=G[nxt[k]][k];
		k=nxt[k];
	}
	cout<<min(cl,acl)<<"\n";
	return 0;
}
