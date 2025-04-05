#include <bits/stdc++.h>
using namespace std;

int zadu[1005];
int dp[1005][35];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T, W;
	cin >> T >> W;

	for (int i = 1; i <= T; i++) {
		cin >> zadu[i];
	}

	if (zadu[1] == 1) {
		dp[1][0] = 1;
	}
	else {
		dp[1][1] = 1;
	}

	for (int i = 2; i <= T; i++) {
		for (int j = 0; j <= i + 1 && j <= W ; j++) {
			dp[i][j] = dp[i - 1][j];
			if (zadu[i] == 1 && j%2==0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
			}
			else if (zadu[i] == 2 && j % 2 != 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
			}
			else if (j != 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}

	int ans = 0;
	for (int j = 0; j <= W; j++) {
		ans = max(ans, dp[T][j]);
	}

	cout << ans;
}