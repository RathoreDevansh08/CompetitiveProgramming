#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int>a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        int fl = 0, j = 0, ans = 0;
        while(j < n)
        {
            if(j == (n-1))
            {
                if(!fl && a[j]) ans++;
                break;
            }

            if(fl == 0)
            {
                if(!a[j] && !a[j+1])
                {
                    j += 2;
                }
                else if(!a[j] && a[j+1])
                {
                    j += 1;
                }
                else if(a[j] && !a[j+1])
                {
                    ans++; j += 2;
                }
                else if(a[j] && a[j+1])
                {
                    ans++; j += 1;
                }
            }
            else
            {
                if(!a[j] && !a[j+1])
                {
                    j += 1;
                }
                else if(!a[j] && a[j+1])
                {
                    j += 2;
                }
                else if(a[j] && !a[j+1])
                {
                    j += 1;
                }
                else if(a[j] && a[j+1])
                {
                    j += 2;
                }
            }

            fl = 1 - fl;
        }

        cout<<ans<<"\n";
    }

    return 0;
}
