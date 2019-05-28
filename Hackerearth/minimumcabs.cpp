#include<iostream>
#include<set>
#include<utility>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,a,b,f=0,c,d;
	cin>>n;
	
	multiset<pair<int,int>>s;
	multiset<int>v;
	multiset<int>::iterator it;
	//vector<int>v;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b>>c>>d;
		s.insert(make_pair(a*60+b,c*60+d));
	}
		
	for(auto& e:s)
	{
		if(f==0)
		{
			v.insert(e.second);
			it=v.begin();
			f=1;
		}
		else
		{
			if(e.first<=*it)
			{
				v.insert(e.second);
			}
			else
			{
				v.erase(it);
				v.insert(e.second);
			}
			it=v.begin();
		}
		
	}
	cout<<v.size();
	
	return 0;
}
