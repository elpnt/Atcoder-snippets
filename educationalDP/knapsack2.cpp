#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<tuple>
#include<map>
#define ll long long
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define REP(i, n) FOR(i, 0, n)
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

const int MAX_N = 110;
const int MAX_V = 110000;
const ll INF = 1LL << 60;

int N;
ll W, w[MAX_N], v[MAX_N];
ll dp[MAX_N][MAX_V] = {0};

int main() {
    // 入力
    cin >> N >> W;
    REP(i, N) cin >> w[i] >> v[i];

    // DP初期化
    REP(i, MAX_N) REP(j, MAX_V) dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 0; i < N; i++) {
        for (int sum_v = 0; sum_v < MAX_V; sum_v++) {
            if (sum_v - v[i] >= 0) {
                chmin(dp[i+1][sum_v], dp[i][sum_v - v[i]] + w[i]);
            }
            chmin(dp[i+1][sum_v], dp[i][sum_v]);
        }
    }

    ll ans = 0;
    for (int sum_v = 0; sum_v < MAX_V; sum_v++) {
        if (dp[N][sum_v] <= W) {
            ans = sum_v;
        }
    }
    cout << ans << endl;
}
