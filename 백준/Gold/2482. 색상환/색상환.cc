#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000003

long long dp[1002][1002];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[i][0] = 1;
		dp[i][1] = i;
	}

	for (int i = 4; i <= N; i++) {
		for (int j = 2; j <= K; j++) {
			dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	cout << dp[N][K] % MOD;
}