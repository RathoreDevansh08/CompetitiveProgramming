#include<iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    int n;
    cin>>n;
    char S[n],T[n];
    
    for(int i=0;i<n;i++)cin>>S[i];
    for(int i=0;i<n;i++)cin>>T[i];
    
    int k=0,ct=0;
    while(k<n)
    {
        if(S[k]==T[k]){k++;continue;}
        if(S[k]<T[k])
        {
            ct+=((int)(T[k]-S[k]))%13 + ((int)(T[k]-S[k]))/13;
        }
        else
        {
            T[k]=(char)((int)T[k]+26);
            ct+=((int)(T[k]-S[k]))%13 + ((int)(T[k]-S[k]))/13;
        }
        k++;
    }
    cout<<ct;
    return 0;
}
