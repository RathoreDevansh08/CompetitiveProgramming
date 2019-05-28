#include<iostream>

using namespace std;

int t,n;
long int k,a[100001],mx;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		mx=0;
		for(int i=0;i<n;i++) 
		{
			cin>>a[i];
			if(a[i]>k)a[i]=0;
			else if(i>0)a[i]+=a[i-1];
			mx=max(mx,a[i]);
		}
		cout<<mx<<"\n";
	}
	return 0;
}
