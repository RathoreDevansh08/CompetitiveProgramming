#include<iostream>
#include<vector>

using namespace std;

int vol(i,j,int a[])
{
	int hh=max(a[)
}

int main()
{
	int t;
	string st;
	cin>>t;
	
	while(t--)
	{
		cin>>m>>n;
		int a[m][n],b[m][n],V=0;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				{cin>>a[i][j];b[i][j]=0;}
		for(int i=1;i<m-1;i++)
		{
			for(int j=1;j<n-1;j++)
			{
				if(a[i][j]<=a[i][j+1] && a[i][j]<=a[i+1][j] && a[i][j]<=a[i][j-1] && a[i][j]<=a[i-1][j])                       {
					b[i][j]=1;
				}
			}
		}
		
		for(int i=1;i<m-1;i++)
		{
			for(int j=1;j<n-1;j++)
			{
				if(b[i][j]==1)
				{
					V+=vol(i,j);
				}
			}
		}
		getline(cin,st);
	}
	return 0;
}
