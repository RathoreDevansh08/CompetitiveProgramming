#include<bits/stdc++.h>
using namespace std;

#define MAX 1005
#define inf 1000000007
#define pb push_back
#define mp make_pair
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef long long int ll;
typedef vector<int> vi;

string st;
int t,mn,mx,a,b,r,c,f=0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin>>r>>c;
	
	if(r==1 && c==1) {cout<<0;return 0;}
	
	int cnt=2, j=0, ar[c];
	fr(j,0,c-1)
	{
		cout<<cnt<<" ";
		ar[j] = cnt;
		cnt++;
	}
	cout<<"\n";
	
	if(c==1)
	{
		fr(i,1,r-1)
		{
			cout<<cnt<<"\n";
			cnt++;
		}
		return 0;
	}
	else
		fr(i,1,r-1)
		{
			fr(j,0,c-1)
			{
				cout<<ar[j]*cnt<<" ";
			}
			cnt++;
			cout<<"\n";
		}
	
	return 0;
}
