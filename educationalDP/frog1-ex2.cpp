#include<iostream>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using namespace std;

const int INF = 1e9;

int main() {
    int N; cin >> N;
    int h[N];
    for (int i = 0; i < N; i++) cin >> h[i];
    int dp[N];
    for (int i = 0; i < N; i++) dp[i] = INF;
    dp[0] = 0;

    // 配るDP
    for (int i = 0; i < N+2; i++) {
        chmin(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
        chmin(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
    }
    cout << dp[N-1] << endl;
}
