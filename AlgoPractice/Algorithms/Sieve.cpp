#include<bits/stdc++.h>
using namespace std;

void sieve(int n)
{
    int prime[n+1];

    for(int i=2;i<=n;i++)
    {
        prime[i] = 1;
    }

    for(int p=2; p*p<=n; p++)
    {
        if(prime[p])
        {
            for(int j=p*p;j<=n;j+=p)
            {
                prime[j] = 0;
            }
        }
    }

    for(int i=2;i<=n;i++)
    {
        if(prime[i]) cout<<i<<" ";
    }
    cout<<"\n";
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;
    sieve(n);

    return 0;
}
