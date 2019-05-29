#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;

const int M = 505;
int n, a[M], d[M][M];

void kill() 
{
  for (int len = 1; len <= n; ++len)
    for (int i = 0; i + len <= n; ++i) 
    {
      int j = i + len;
      int &cur = d[i][j];
      cur = d[i + 1][j] + 1;
      for (int k = i + 1; k < j; ++k)
        if (a[i] == a[k]) 
        {
          int bon = d[i + 1][k] + d[k + 1][j];
          cur = min(cur, bon);
        }
    }
  cout << d[0][n] << endl;
}
int main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  kill();
}
