#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin>>n;

    int a[n];
    set<int>left, right;
    set<int>::iterator it, it2;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        right.insert(a[i]);
    }

    int mad = -10000000;
    for(int i=0;i<n;i++)
    {
        if(i == 0)
        {
            //right.erase(a[i]);
            left.insert(a[i]);
            right.insert(a[i]);

            it = right.find(a[i]);
            int rig_sm = distance(right.begin(), it);

            int rs = right.size();
            mad = max(mad, (rig_sm));


            right.erase(a[i]);
        }
        else if(i == (n-1))
        {
            left.insert(a[i]);
            right.insert(a[i]);


            int lef_la = distance(left.begin(), left.find(a[i]));
            int ls = left.size();
            mad = max(mad, (ls - lef_la -1));


            right.erase(a[i]);
        }
        else
        {
            left.insert(a[i]);
            right.insert(a[i]);

            int rig_sm = distance(right.begin(), right.find(a[i]));
            int rs = right.size();

            int lef_la = distance(left.begin(), left.find(a[i]));
            int ls = left.size();

            int m = max((ls - lef_la -1), (rig_sm));
            mad = max(mad, m);

            right.erase(a[i]);
        }

        //cout<<mad<<"-----\n";
    }

    cout<<mad<<"\n";
    return 0;
}
