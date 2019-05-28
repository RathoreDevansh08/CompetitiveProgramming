#include<iostream>
#include<vector>
#include<iterator>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		vector<int>a(n);
		vector<int>::iterator it;
		for(int i=0;i<n;i++) cin>>a[i];
		
		int j=0,z;
		while(k>0 && j<n)
		{
			int mi=a[j],mii=j;
			if(j+k<n)
			{
				for(int l=j+1;l<=j+k;l++)
				{
					if(mi>a[l]){mii=l;mi=a[l];}
				}
			}
			else if(j+1<n)
			{
				for(int l=j+1;l<n;l++)
				{
					if(mi>a[l]){mii=l;mi=a[l];}
				}
			}
			
			if(mi<a[j])
			{
				z=a[mii];
				a.erase(a.begin()+mii);
				it=a.begin();
				a.insert(it,z);
				k-=(mii-j);
			}
			j++;
		}
		for(int i=0;i<n;i++)cout<<a[i]<<" ";
		cout<<"\n";
	}
	
	return 0;
}
