#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int t,n,sum,mx,j;
char st[1000005];
int a[1000005],mem[1000005];

int dp(int i)
{
	if(i>=n)return 0;
	if(mem[i]==-1)
	{ 
		if(i+2<n && a[i+2]<3)mem[i]=3+dp(i+3);
		else mem[i]=0;//dp(i+1);
	}
	return mem[i];
}

int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",st);
		memset(mem,-1,sizeof mem);
		memset(a,10,sizeof a);
		n=1;a[0]=1;
		while(st[n])
		{
			if(st[n]==st[n-1])a[n]=a[n-1]+1;
			else a[n]=1;
			n++;
		}
		sum=0;mx=0;
		/*for(int i=0;i<n-2;i++)
		{
			if(a[i+2]<3){sum+=3;mx=max(mx,sum);i+=2;}
			else {sum=0;}
		}*/
		j=0;
		while(j<n-2) 
		{
			if(mem[j]==-1 && a[j+2]<3)mx=max(mx,dp(j));
			j++;
		}
		cout<<n-mx<<"\n";
	}
	return 0;
}
