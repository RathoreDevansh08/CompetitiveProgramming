#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n;char c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		long long int A,B,C;
		vector<long long int>a(n);
		
		for(int i=0;i<n;i++)cin>>a[i];
		cin>>A>>B>>C;
		A=A%C;B=B%C;
		
		for(int i=0;i<n;i++)
		{
			cin>>c;
			if(c=='R')
			{
				reverse(a.begin()+i,a.end());
			}
			else if(c=='A')
			{
				for(int j=i;j<n;j++)a[j]=((a[j]%C)+A)%C;
			}
			else
			{
				for(int j=i;j<n;j++)a[j]=((a[j]%C)*B)%C;
			}
		}
		for(int i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
