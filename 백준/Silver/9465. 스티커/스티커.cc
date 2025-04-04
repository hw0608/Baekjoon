#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		vector<int> cols(n + 1);
		vector<vector<int>> sticker{ cols, cols };
		vector<vector<int>> dp{ cols, cols };

		for (int i = 0; i < n * 2; i++) {
			cin >> sticker[i / n][i % n];
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[1][0] + sticker[0][1];
		dp[1][1] = sticker[0][0] + sticker[1][1];

		for (int i = 2; i < n; i++) {
			dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + sticker[0][i];
			dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + sticker[1][i];
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}