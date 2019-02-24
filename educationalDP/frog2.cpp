#include<iostream>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

const int INF = 1e9;

int main() {
    int N, K;
    cin >> N >> K;
    int h[100010];
    for (int i = 0; i < N; i++) cin >> h[i];
    int dp[110000];
    for (int i = 0; i < N; i++) dp[i] = INF;
    dp[0] = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j <= K; j++) {
            chmin(dp[i+j], dp[i] + abs(h[i] - h[i+j]));
        }
    }
    cout << dp[N-1] << endl;
}
