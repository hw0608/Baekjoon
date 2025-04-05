#include <bits/stdc++.h>
using namespace std;

int n, m;

char arr[1005][1005];
int dp[1005][1005];

int dx[3] = { -1,-1,0 };
int dy[3] = { -1,0,-1 };

bool OOB(int x, int y) {
	return x <= 0 || x > n || y <= 0 || y > m;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dp[i][j] = arr[i][j] - '0';
			if (arr[i][j] == '0') continue;
			
			dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			ans = max(ans, dp[i][j]);
		}
	}

	cout << ans * ans;
}