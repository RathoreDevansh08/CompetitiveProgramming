#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    string s;
    int i=0,j,n;
    getline(cin,s);
    n=s.length();
    char c[n];
    if(n==1 && s[0]=='?')c[0]='a';
    if(n>=2 && s[0]=='?' && s[1]!='a'){c[0]='a';i=1;}
    while(i<n)
    {
        if(s[i]=='?')
        {
            if(c[i-1]=='a')c[i]='b';
            else if(c[i-1]=='b')c[i]='a';
            if(i<n-1 && s[i+1]=='a')c[i]='b';
        }
        else
        {
            c[i]=s[i];
        }
        i++;
    }
    for(int i=0;i<n;i++)cout<<c[i];
    return 0;
}
