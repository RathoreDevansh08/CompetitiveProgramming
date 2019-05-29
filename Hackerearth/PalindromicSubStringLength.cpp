#include <bits/stdc++.h>         //Editorial Solution
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int c=0,f=0,m=1,x=0,y=0;
        for(int i=0;i<s.size();i++)
        {
            f=0;
            c=0;
            for(int j=i-1,k=i;j>=0&&k<s.size()&&f==0;k++,j--)
            {
                if(s[j]==s[k])
                {
                    c=c+2;
                    if(c>m)
                    {
                        m=c;
                        //x=j;
                        //y=k;
                    }
                }
                else
                f=1;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            f=0;
            c=1;
            for(int j=i-1,k=i+1;j>=0&&k<s.size()&&f==0;k++,j--)
            {
                if(s[j]==s[k])
                {
                    c=c+2;
                    if(c>m)
                    {
                        m=c;
                        x=j;
                        y=k;
                    }
                }
                else f=1;
            }
        }
        int l=m;
        if(l==1) cout<<"NOT PRIME"<<endl;
        else if(l==2) cout<<"PRIME"<<endl;
        else
        {
            int ff=0;
            for(int i=2;i*i<=l&&ff==0;i++)
            {
                if(l%i==0)ff=1;
            }
            if(ff==0)cout<<"PRIME"<<endl;
            else cout<<"NOT PRIME"<<endl;
        }
    }
    return 0;
}
