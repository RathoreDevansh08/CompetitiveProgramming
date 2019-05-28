#include<iostream>
#include<set>
#include<algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,x;
	vector<int>s;
	
	cin>>n;
	for(int i=0;i<n;i++) {cin>>x;s.push_back(x);}
	
	sort(s.begin(),s.end());
	
	int ma=-1;
	for(int i=0;i<n-1;i++)
	{
		if(i==0)
		{
			ma=max(ma,s[1]-s[0]);
			ma=max(ma,s[2]-s[0]);
		}
		else if(i==n-2)
		{
			ma=max(ma,s[n-1]-s[n-2]);
		}
		else
		{
			ma=max(ma,s[i+2]-s[i]);
		}
	}
	cout<<ma;
	return 0;
}
