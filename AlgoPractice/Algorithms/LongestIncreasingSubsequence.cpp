// Longrst Increasing Subsequence in O(N*log(N))
/*
1. If A[i] is smallest among all end candidates of active lists, we will start new active list of length 1.
2. If A[i] is largest among all end candidates of active lists, we will clone the largest active
   list, and extend it by A[i].
3. If A[i] is in between, we will find a list with largest end element that is smaller than A[i].
   Clone and extend this list by A[i]. We will discard all other lists of same length as that of this modified list.
*/
// ONly applicable, when to find strictly increasing subsequence.

#include<bits/stdc++.h>
using namespace std;

int getIndex(vector<int> &t, int l, int r, int k)
{
    while(r - l > 1) {
        int m = (l + r) / 2;
        if (k <= t[m]) r = m;
        else l = m;
    }
    return r;
}

int lis(vector<int> &v)
{
    if(v.size() == 0) return 0;

    int length = 1;
    vector<int> tail(v.size(), 0);

    tail[0] = v[0];
    for(int i=1; i<v.size(); i++)
    {
        if(v[i] < tail[0])
        {
            tail[0] = v[i];
        }
        else if(v[i] > tail[length - 1])
        {
            tail[length++] = v[i];
        }
        else
        {
            tail[ getIndex(tail, -1, length -1 , v[i]) ] = v[i];
        }
    }

    return length;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v{1, 5, 13, 9, 7, 3, 11};

    cout<<"length :"<<lis(v)<<"\n";
    return 0;
}
