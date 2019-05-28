#include<bits/stdc++.h>
using namespace std;

int longest_special_subseq(int n, int k,string str) 
{
    int pos[150],val[150],m=0,b,max,M=1;
    char c;
    for(int i=0;i<150;i++){pos[i]=-1;val[i]=-1;}
    
    while(str[m]!='\0')
    {
        c=str[m];
        b=(int)c;
        pos[b]=m;
        max=0;
        for(int j=(int)'a';j<=(int)'z';j++)
        {
            if(pos[j]!=-1 && abs(j-b)<=k)
            {
                if(val[j]>max)
                {
                    max=val[j];
                }
            }
        }
        val[b]=max+1;
        //cout<<val[b];
        m++;
        if(max+1>M)M=max+1;
    }
    return M;
}

int main() 
{
    int t, n, k;
    string str;
    cin >> t;
    while(t--) {
        cin >> n >> k;
        cin >> str;
        cout << longest_special_subseq(n,k,str) << endl;
    }
    return 0;
}
