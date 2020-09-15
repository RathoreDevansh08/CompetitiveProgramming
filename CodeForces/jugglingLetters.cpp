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
        string st[n];
        int ch[26];
        for(int i=0;i<26;i++) ch[i]=0;

        for(int i=0;i<n;i++)
        {
            cin>>st[i];
            int j=0;
            while(j<st[i].length())
            {
                ch[(int)((char)st[i][j] - 'a')]++;
                j++;
            }
        }

        int fl=0;
        for(int i=0;i<26;i++)
        {
            if(ch[i] % n == 0) fl = 0;
            else {fl =1;break;}
        }

        if(fl) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;
}
