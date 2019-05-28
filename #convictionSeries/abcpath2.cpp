#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int n,m;
char a[60][60];
bool visited[60][60];

int solve(int i,int j)
{
	int ma=0;
	int in,jn;
 	if(i<=0 || i>n || j<=0 || j>m)return 0;
 	for(in=-1;in<=1;in++)
	{
		for(int jn=-1;jn<=1;jn++)
		{
			if(in==0&&jn==0)continue;

			if(a[i + in][j + jn] == a[i][j]+1 && !visited[i + in][j + jn])
			{
				visited[i + in][j + jn]=true;
				ma=max(ma,solve(i + in,j + jn));
			}

		}
	} 
return ma+1;
}

int main()
{
int index=1;
while(1)
{
	scanf("%d %d",&n,&m);
	if(n==0&&m==0)break;
	if(n==0||m==0)
	{
		cout<<0<<endl;
		continue;
	}

	memset(a,'-',sizeof a);
	for(int i = 1;i<=n;i++)
	{
		char str[50];
		scanf("%s",str);
		for(int j=0;j<=m;j++)
		{
			a[i][j+1] = str[j];
		}
	} // input taken

memset(visited,false,sizeof visited);
int ma=0;
for(int i=1;i<=n;i++)
for(int j=1;j<=m;j++)
{
if(a[i][j]=='A')
{
visited[i][j] = true;
ma = max(ma,solve(i,j));
}
}

cout<<"Case "<<index<<": "<<ma<<endl;
index++;
}

return 0;

}
