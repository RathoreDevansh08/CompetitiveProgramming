#include<iostream>

using namespace std;

int main()
{
	string s[26];
	s[0]="A";
	for(int i=1;i<26;i++)
	{
		s[i]="";
		s[i]+=(char)(65+i);
		for(int j=0;j<i-1;j++) s[i]+=" ";
		s[i]+=(char)(65+i);
		for(int j=0;j<i-1;j++) s[i]+=" ";
		s[i]+=(char)(65+i);
		//cout<<s[i]<<"\n";
	}
	
	int n;
	cin>>n;
	for(int i=n-1;i>0;--i)
	{
		for(int j=1;j<n-i;j++)cout<<" ";
		cout<<s[i]<<"\n";
	}
	for(int i=n-1;i>=0;--i) cout<<(char)(65+i);
	for(int i=1;i<=n-1;i++) cout<<(char)(65+i);
	cout<<"\n";
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<n-i;j++)cout<<" ";
		cout<<s[i]<<"\n";
	}
	return 0;
}
