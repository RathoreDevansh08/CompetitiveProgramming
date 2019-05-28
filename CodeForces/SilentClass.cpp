#include<iostream>
#include<vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);	
	
	int n;
	unsigned long long int count=0,x;
	cin>>n;
	string st;
	vector<int>c(26,0);
	for(int i=0;i<n;i++)
	{
		cin>>st;
		c[(int)st[0]-97]++;
	}
	for(int i=0;i<26;i++)
	{
		x=c[i]/2;
		if(x>=2) count+= x*(x-1)/2;
		x=c[i]-x;
		if(x>=2) count+= x*(x-1)/2;
	}
	cout<<count<<"\n";
	return 0;
}
