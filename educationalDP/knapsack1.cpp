#include<iostream>
#define ll long long
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

int N;
ll W, w[110], v[110];
ll dp[110][100100] = {0};

int main() {
    cin >> N >> W;
    for (int i = 0; i < N; i++) cin >> w[i] >> v[i];

    for (int i = 0; i < N; i++) {
        for (int sum_w = 0; sum_w <= W; sum_w++) {
            // i番目の品物を選ぶ
            if (sum_w - w[i] >= 0) {
                chmax(dp[i+1][sum_w], dp[i][sum_w - w[i]] + v[i]);
            }

            // i番目の品物を選ばない
            chmax(dp[i+1][sum_w], dp[i][sum_w]);
        }
    }
    cout << dp[N][W] << endl;
}
