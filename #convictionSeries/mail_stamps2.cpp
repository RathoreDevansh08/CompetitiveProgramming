#include<iostream>
#include<vector>
#include<map>
#include<iterator>
#include<utility>
using namespace std;

typedef long long int ll;

map<ll,vector<ll>> mp;
map<ll,vector<ll>>::iterator it;
map<ll,ll> vis;

void dfs(ll s)
{
    cout<<s<<" ";
    vis[s]=1;

    for(ll i : mp[s])
    {
    	if(!vis[i])dfs(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    ll n,a,b;
    ll id;
    cin>>n;
    
    for(ll i=0;i<n;i++)
    {
        cin>>a>>b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        vis[a]=vis[b]=0;
    }

    for(it=mp.begin();it!=mp.end();++it)
    {
        if(it->second.size()==1)
        {
            id=it->first;
            break;
        }
    }

    dfs(id);
    cout<<"\n";
    
    return 0;
}
