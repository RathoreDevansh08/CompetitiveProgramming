#include <bits/stdc++.h>                 //Editorial Solution
using namespace std;
#define ll long long
#define t int t; cin>>t; while(t--)
#define clear(a,x) memset(a,x,sizeof(a))
#define boost ios_base::sync_with_stdio(false)
#define show(a) for(int bm=0;bm<a.size();bm++)cout<<a[bm]<<" ";
#define sc1(x) scanf("%d",&x)
#define sc2(x,y) scanf("%d%d",&x,&y)
#define sc3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sc4(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define sc5(a,b,c,d,e) scanf("%d%d%d%d%d",&a,&b,&c,&d,&e)
#define pr1(x) printf("%d\n",x)
#define pr2(x,y) printf("%d %d\n",x,y)
#define pr3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pr4(a,b,c,d) printf("%d %d %d %d\n",a,b,c,d)
#define pr5(a,b,c,d,e) printf("%d %d %d %d %d\n",a,b,c,d,e)
#define scl(x) scanf("%lld",&x)
#define prl(x) printf("%lld\n",x)
#define u(i,a,b) for(i=a;i<b;i++)
#define d(i,a,b) for(i=a;i>b;i--)
#define all(x) x.begin(),x.end() 
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define mp(x,y) make_pair(x,y) 
#define ff first
#define ss second
#define mod 1000000007
void multiply(ll a[3][3],ll b[3][3])
{
    ll mul[3][3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                ll temp=((a[i][k]%mod)*(b[k][j]%mod))%mod;
                mul[i][j] = ((mul[i][j]%mod)+(temp%mod))%mod;
            }
        }
    }
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            a[i][j] = mul[i][j]%mod;  
}
ll power(ll F[3][3],ll n)
{
    ll M[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}};
    if (n==1){
        return (F[0][0]%mod + F[0][1]%mod)%mod;
    }
 
    power(F, n/2);
 
    multiply(F, F);
 
    if (n%2 != 0)
        multiply(F, M);
 
    return ((F[0][0]%mod) + (F[0][1]%mod))%mod ;
}
ll findNthTerm(ll n)
{
    ll F[3][3] = {{1,1,1}, {1,0,0}, {0,1,0}} ;
    return power(F, n-2);
}
int main()
{
    t{
        ll n;
        assert(n>= 1 && n<=1000000000000000000);
        scl(n);
        prl(findNthTerm(n+2));
    }
}
