#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, k;
    cin>>t;

    while(t--)
    {
        cin>>n>>k;
        int v = k, b = (n - k)/2;

        if(k > n) cout<< abs(v-n)<<"\n";
        else if (n%2 == k%2)
        {
            cout<<"0\n";
        }
        else
        {
            cout<<"1\n";
        }
    }

    return 0;
}
