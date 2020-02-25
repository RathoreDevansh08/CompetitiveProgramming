// Devansh Singh Rathore (@DSR08)

#define BZ
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll = int64_t;
using ld = long double;
using ull = uint64_t;
using namespace std;
using namespace __gnu_pbds;
typedef vector <int> vi;
typedef pair <int, int> ii;
const int INF = 1 << 30;
const int maxn = 100010;

struct Lib {
	int n, t, m, points_sum, id;
	vi books;
	Lib () {}
	Lib (int _n, int _t, int _m) {
		n = _n;
		t = _t;
		m = _m;
	}
};

bool compare(Lib x, Lib y)
{
	return (((float)x.points_sum/x.t) > ((float)y.points_sum/y.t));
}

int main() 
{
#ifdef BZ
    freopen("c_incunabula.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cout.tie(nullptr); cout.setf(ios::fixed); 
    cout.precision(6);    
    
    //INPUT
    int b, l, d;
    cin >> b >> l >> d;    
    vi scores (b);
    for (int i = 0; i < b; i++) 
    {
    	cin >> scores[i];
    }    
    vector <Lib> a(l);    
    for (int i = 0; i < l; i++) {
    	int n, t, m;
    	cin >> n >> t >> m;
    	a[i] = Lib(n, t, m);    	
    	vi tem (n);
    	a[i].id=i;
    	a[i].points_sum=0;
    	for (int j = 0; j < n; j++) 
    	{
    		cin >> tem[j];
    		a[i].points_sum += scores[tem[j]];
    	}
    	a[i].books = tem;    	
    	//Sorting in descending order on basis of scores.
    	sort (a[i].books.begin(), a[i].books.end(), [&] (int x, int y) 
    	{
    		return scores[x] > scores[y];
    	});
    }

	// GREEDY
	
	long int no_lib=l, A=l;
	map <int, int> used;
	
	cout<<A<<"\n";
	ll ans = 0;
	while(no_lib--)
	{
		sort(a.begin(), a.end(), compare);

		//for(int i=0;i<l;i++)
		//{
		//	cout<<((float) a[i].points_sum/a[i].t)<<"\n";
		//}
    
    	cout<<a[0].id<<" "<<a[0].n<<"\n";
    	cerr << a[0].id << "\n";
    	ans += a[0].points_sum;
    	for(int i=0; i<a[0].n; i++)
    	{
    		cout<<a[0].books[i]<<" ";
    		used[ a[0].books[i] ] = 1;
    	}
    	cout<<"\n";
    	
    	
    	a.erase(a.begin());
    	
    	int r=0;
    	for(auto e: a)
    	{
    		r=0;
    		for( int k=0; k<e.n; k++)
    		{
    			int f=e.books[k];
    			if(f!=-1 && used[f])
    			{
    				e.points_sum -= scores[f];
    				r++;
    				e.books[k]=-1;
    			}
    		}
    		e.n -= r;
    		
    		sort (a[0].books.begin(), a[0].books.end(), [&] (int x, int y) 
			{
				if(x==-1) return false;
				if (y == -1) return true;
				return scores[x] > scores[y];
			});
    	}
    	
    }
    
    cerr << ans << "\n";
}
















