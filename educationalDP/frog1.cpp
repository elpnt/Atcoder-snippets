#include<iostream>
using namespace std;

const int INF = 1e9;

int main() {
    int N;
    int h[100010];
    cin >> N;
    for (int i = 0; i < N; i++) cin >> h[i];

    // 1. DPテーブルの初期化
    int dp[100010];
    for (int i = 0; i < N; i++) dp[i] = INF;
    dp[0] = 0;

    // 2. DPテーブル更新方策
    // -- 足場iから足場jへのコストをc_ijとすると、足場iにたどり着くまでのコストは
    // -- min(c_(i-1)i, c_(i-2)i)
    for (int i = 1; i < N; i++) {
        if (i == 1) {
            dp[i] = abs(h[i] - h[0]);
        } else {
            int cost1 = dp[i-1] + abs(h[i] - h[i-1]);
            int cost2 = dp[i-2] + abs(h[i] - h[i-2]);
            dp[i] = min(cost1, cost2);
        }
    }
    cout << dp[N-1] << endl;
}
