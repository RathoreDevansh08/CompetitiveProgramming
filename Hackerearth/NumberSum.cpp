#include <bits/stdc++.h>
using namespace std;
const int N = 5E3 + 5;
int a[N];
int f[N];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
        cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i ++) {
        int mex = 1;
        memset(f, 0, sizeof f);
        for(int j = i; j < n; j ++) {
            if(a[j] < N)
                f[a[j]] = 1;
            while(f[mex])
                mex ++;
            ans += mex;
        }
    }
    cout << ans;
    return 0;
}
