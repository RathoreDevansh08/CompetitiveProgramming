#include<bits/stdc++.h>
using namespace std;

int kadane(int ar[], int n)
{
    int max_ending_here = 0, max_so_far = 0;

    for(int i=0;i<n;i++)
    {
        max_ending_here += ar[i];
        if(max_ending_here > max_so_far) max_so_far = max_ending_here;
        else if(max_ending_here < 0) max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int ar[] = {3, -7, 1, 0, 20, -12, -13};
    int n = sizeof(ar)/sizeof(ar[0]);

    cout<<kadane(ar, n)<<"\n";

    return 0;
}
