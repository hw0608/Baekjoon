#include <bits/stdc++.h>
using namespace std;

long long dp[35];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	if (N % 2 != 0) {
		cout << 0;
		return 0;
	}

	dp[2] = 3;

	for (int i = 4; i <= N; i++) {
		dp[i] += dp[i - 2] * dp[2] + 2;

		for (int j = i - 2; j >= 4; j -= 2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[N];
}