#include<iostream>

using namespace std;

int t,n,r;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n<2) {cout<<"-1\n";continue;}
		
		r=n%7;
		if(r==0) cout<<n/7<<"\n";
		else if(r==1) cout<<(n/7-1)+2<<"\n";
		else if(r==2) cout<<n/7+1<<"\n";
		else if(r==3) cout<<n/7+1<<"\n";
		else if(r==4) cout<<n/7+2<<"\n";
		else if(r==5) cout<<n/7+1<<"\n";
		else cout<<n/7+2<<"\n";
	}
	return 0;
}
