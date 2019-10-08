#include <bits/stdc++.h>

using namespace std;

#define inf 1000000007
#define pb push_back
#define fr(i,a,b) for(int i=a;i<=b;i++) 
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

//In a perfect scenario, the maximum beauty of the original array is just a sum of m·k largest elements.
//In fact, such scenario is always available regardless of the elements.

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m, k;
    cin>>n>>m>>k;

    vector<pii> a(n);
    fr(i,0,n-1) 
    {
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end(), greater<pii>());

    vi ind(m*k);
    ll beauty = 0;
    fr(i,0,m*k-1) 
    {
        beauty += a[i].first;
        ind[i] = a[i].second;
    }

    sort(ind.begin(), ind.end());

    vi div(k-1);
    fr(i,0,k-2) div[i] = ind[ (i+1) * m - 1];

    cout<<beauty<<"\n";
    for(auto e : div) cout<<e+1<<" "; cout<<"\n";

    return 0;
}
