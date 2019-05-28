#include <bits/stdc++.h>
using namespace std;

long long getSubstringWithEqual01(string str)
{
	int n = str.length();

	map< int, int > mp;
	mp[0] = 1;

	int zc = 0, oc = 0;
	long long res = 0; 
	for (int i = 0; i < n; ++i)
	{
		if (str[i] == '0') zc++;
		else if (str[i] == '1') oc++;

		res = res + mp[zc-oc];
		mp[zc-oc]++;
	}
	return res;
}

long long a[1000005],s[1000005];
int main()
{
	int n; cin>>n;
	string s="";
	for(int i=0;i<n;++i)
	{
		cin>>a[i];
		if(a[i]%2==0) s+='0';
		else s+='1';
	}
	cout<<getSubstringWithEqual01(s)<<endl;
}
