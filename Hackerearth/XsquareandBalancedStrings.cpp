#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,i;string st;
	cin>>t;
	while(t--)
	{
		getline(cin,st);
		int a[26]={0};
		i=0;
		while(st[i])
		{
			a[(int)st[i]-97]++;
			i++;
		}
		for(i=0;i<26;i++) if(a[i]%2!=0)break;
		if(i==26) cout<<"1\n";
		else cout<<"-1\n";
	}
	return 0;
}
