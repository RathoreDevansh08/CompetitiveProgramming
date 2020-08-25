#include<bits/stdc++.h>
using namespace std;

int bs(int a[], int l, int r, int n)
{
    if (r >= l)
    {
        int m = (l + r)/2;

        if(a[m] == n) return a[m];
        else if (n < a[m]) bs(a, l, m-1, n);
        else bs(a, m+1, r, n);
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr [] = {2, 3, 5, 7, 9};
    int n=4;

    cout<<bs(arr, 0, (n-1), n)<<"\n";

    return 0;
}
