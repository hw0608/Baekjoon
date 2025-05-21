#include <bits/stdc++.h>
using namespace std;

int sticker[2][100002];
int dp[2][100002];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int n;
		cin >> n;

		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> sticker[i][j];
				dp[i][j] = 0;
			}
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[1][0] + sticker[0][1];
		dp[1][1] = sticker[0][0] + sticker[1][1];


		for (int j = 2; j < n; j++) {
			for (int i = 0; i < 2; i++) {
				dp[i][j] = max(max(dp[0][j - 2], dp[1][j - 2]), dp[(i + 1) % 2][j - 1]) + sticker[i][j];
			}
		}

		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}