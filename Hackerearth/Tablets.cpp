#include<iostream>

using namespace std;

int n, health[100001], tab[100001];
long int sum;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>n;
	for(int i=0;i<n;i++) {cin>>health[i];tab[i]=1;}
	for(int i=0;i<n-1;i++)
	{
		//if(health[i]>health[i+1] && tab[i]==1) tab[i]=2;
		//else 
		if(health[i]<health[i+1]) tab[i+1]=tab[i]+1;
	}
	for(int i=n-1;i>=1;--i)
	{
	    if(health[i-1]>health[i] && tab[i-1]<=tab[i]) tab[i-1]=tab[i]+1;
	}
	sum=0;
	for(int i=0;i<n;i++) sum+=tab[i];
	cout<<sum<<"\n";
	return 0;
}
