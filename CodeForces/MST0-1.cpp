#include<bits/stdc++.h>

using namespace std;


class UnionFind
{
	public:
	vector<int> rank, par, vert_per_comp;
	int n_comp;
	
	void reset(int n)
	{
		n_comp = n;
		rank.clear();
		rank.assign(n, 0);
		par.clear();
		par.resize(n);
		vert_per_comp.clear();
		vert_per_comp.assign(n, 1);
		
		for(int i = 0;i < n;i++)
			par[i] = i;	
	}
	
	int findSet(int x)
	{
		int repx = x, u;
		
		while(par[repx] != repx)
			repx = par[repx];
			
		while(par[x] != x)	// Path compression
		{
			u = par[x];
			par[x] = repx;
			x = u;
		}
		
		return repx;
	}
	
	bool isSame(int u, int v)
	{
		return findSet(u) == findSet(v);
	}
	
	void unionSet(int u, int v)
	{
		u = findSet(u), v = findSet(v);
		if(u == v)
			return;
			
		if(rank[u] > rank[v])
		{
			par[v] = u;
			vert_per_comp[u] += vert_per_comp[v];
		}
		else if(rank[u] < rank[v])
		{
			par[u] = v;
			vert_per_comp[v] += vert_per_comp[u];
		}
		else
		{
			par[v] = u;
			rank[u] ++;
			vert_per_comp[u] += vert_per_comp[v];
		}
		n_comp --;
	}
	
	int get_num_vert(int u)
	{
		return vert_per_comp[findSet(u)];
	}
};

int n, m;
UnionFind ufds;
vector<vector<int> > a;

void reset()
{
	a.clear();
	a.resize(n);
	ufds.reset(n);
}

void read()
{
	cin>>n>>m;
	reset();
	
	int u, v;
	for(int i = 0;i < m;i++)
	{
		cin>>u>>v;
		u --, v --;
		a[u].push_back(v);
		a[v].push_back(u);
	}
}

int num_edges[100005];

void solve()
{
	for(int u = 0;u < n;u++)
	{
		for(auto v : a[u])
			num_edges[ufds.findSet(v)] = 0;
			
		for(auto v : a[u])
			num_edges[ufds.findSet(v)] ++;
			
		for(auto v : a[u])
		{
			if(num_edges[ufds.findSet(v)] < ufds.get_num_vert(v))
				ufds.unionSet(u, v);
		}
	}
	
	for(auto x : ufds.par)
		cout<<x<<" --\n";
	
	
	cout<<ufds.n_comp - 1<<"\n";
}

int main()
{
	read();
	solve();
	return 0;
}

