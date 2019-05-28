#include<iostream>
#include<vector>
#include<set>

using namespace std;

vector<set<int>>A;
vector<int>conn;

void ae(vector<int>V,int a,int b)
{
	V[a].push_back(b);
	V[b].push_back(a);
}

int main()
{
	int n,m,k=0;
	cin>>n>>m;
	vector<int>V[n];
	
	for(int i=0;i<m;i++)
	{
		cin>>a>>b;
		a--;b--;
		ae(V,a,b);
	}
	
	int y=0;
	set<int>temp;
	temp.insert(0);
	A.push_back(temp);
	conn.push_back(0);
	y=1;
	
	for(int i=1;i<n;i++)        //iterates on elements
	{
		int k=0,f=0;
		while(!f)             //iterates on sets
		{
			int ns=A[k].size(),nn=0,ny=0;
			for(int j=0;j<A[k].size();j++)
			{
				if(conn[k]==0 && V[i].find(A[k][j])!=V[i].end())
				{
					ny++;
				}
				else if(conn[k]==0 && V[i].find(A[k][j])!=V[i].end())
				{
					nn++;
				}
				else if(conn[k]==1 && V[i].find(A[k][j])!=V[i].end())
				{
					
				}
				else if(conn[k]==2 && V[i].find(A[k][j])!=V[i].end())
				{
					cout<<"NO\n";return 0;
				}

			}
		}
	}
}
