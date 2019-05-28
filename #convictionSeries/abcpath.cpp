#include<iostream>
#include<vector>
#include<map>
#include<utility>
using namespace std;

void ae(vector<int> V[], int u, int v) 
{ 
    V[u].push_back(v); 
} 

int C=0;
void dfs(vector<int>V[],int k,char ch[],int time[])
{
	if(time[k]!=0)return;
	time[k]=1;
	if(V[k].empty())
	{
		C=max((int)(((char)ch[k])-((char)'A')),C);
		return;
	}
	for(int i : V[k])
	{
		dfs(V,i,ch,time);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int l,h,w,k,test=1;
	while(true)
	{
	cin>>h>>w;
	if(h==0 && w==0)return 0;
	if(h==0 || w==0)
	{
		cout<<"Case "<<test++<<": "<<0<<"\n";
		continue;
	}
	l=h*w;k=0;
	
	map<pair<int,int>,int>mp;
	char G[h][w];
	vector<int>V[l+1];char ch[l+1];int time[l+1];
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			{cin>>G[i][j];time[k]=0;ch[k]=G[i][j];mp[{i,j}]=k++;}
	
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
		{
		if((i*j)!=0 && G[i-1][j-1]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i-1,j-1}]);
		if(i!=0 && G[i-1][j]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i-1,j}]);
		if(i!=0 && j!=w-1 && G[i-1][j+1]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i-1,j+1}]);
		if(j!=0 && G[i][j-1]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i,j-1}]);
		if(j!=w-1 && G[i][j+1]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i,j+1}]);
		if(i!=h-1 && j!=0 && G[i+1][j-1]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i+1,j-1}]);
		if(i!=h-1 && G[i+1][j]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i+1,j}]);
		if(i!=h-1 && j!=w-1 && G[i+1][j+1]==(char)((char)G[i][j]+1))ae(V,mp[{i,j}],mp[{i+1,j+1}]);
		}
		
	int m=0,kl=0;
		for(int j=0;j<w*h;j++)
		{
			if(ch[j]=='A')
			{
				C=0;
				dfs(V,j,ch,time);
				m=max(m,C);
				kl++;
			}
		}
	if(m==0 && kl==0)m=-1;
	cout<<"Case "<<test++<<": "<<m+1<<"\n";
	}
	return 0;
}
