#include<iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	string st;
	getline(cin,st);
	int n=st.length();
	int a[n],count=0;
	
	for(int i=n-1;i>=0;--i)
	{
		if(st[i]%2==0)count++;
		a[i]=count;
	}
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
