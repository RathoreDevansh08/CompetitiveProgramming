#include<iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n,mx,ct,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n)cin>>mx;
		else {cout<<0<<"\n";continue;}
		
		ct=1;
		for(int i=1;i<n;i++)
		{
			cin>>x;
			if(x>mx)
			{
				ct++;
				mx=x;
			}
		}
		cout<<ct<<"\n";
	}
	
	return 0;
}
