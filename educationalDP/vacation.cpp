#include<iostream>
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

int main() {
    int N; cin >> N;
    int a[N][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }

    int dp[110000][3];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (j == k) continue;
                chmax(dp[i+1][k], dp[i][j] + a[i][k]);
            }
        }
    }

    int ans = 0;
    for (int j = 0; j < 3; j++) chmax(ans, dp[N][j]);
    cout << ans << endl;
}
