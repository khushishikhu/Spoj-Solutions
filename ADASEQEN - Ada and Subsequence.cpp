#include <iostream>
#include <bits/stdc++.h>
int INF = 1 << 30;
using namespace std;
 
const int MAX = 2025;
 
int N, M;
string a, b;
int cost[MAX], dp[MAX][MAX];
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);
   
#endif
 
 
  cin >> N >> M;
    for (int i = 'a'; i <= 'z'; i ++) {
        cin >> cost[i];
    }
    cin >> a >> b;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= M; j ++) {
            if (a[i - 1] == b[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + cost[a[i - 1]];
            }
            else {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    cout << dp[N][M] << endl;
  return 0;
 
}
 
 