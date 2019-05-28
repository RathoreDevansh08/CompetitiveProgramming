#include<bits/stdc++.h>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n,ne=0,po=0,pn,nn;
	long int x,count=0;
	set<long int>pset;
	set<long int>::iterator it,it2;
	for(int i=0;i<n;i++)
	{
		cin>>x;
		pset.insert(x);
	}
	pn=pset.size();
	int u=0;
	while(pset.size()>1)
	{
		u=0;
		cout<<"m";
		it=pset.begin();
		if(pset.find(2*(*it)+1)==pset.end()){pset.insert(2*(*it)+1);u=1;}
		it2=pset.find(2*(*it)+1);
		it2--;
		//count+=distance(it2,it);
		if(u)pset.erase(2*(*it)+1);
		pset.erase(*it);
		
	}
	cout<<count<<"\n";
	return 0;
}
