#include <bits/stdc++.h>
using namespace std;

int N;
int board[105][105];

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

long long dp[105][105];

bool OOB(int a, int b) {
	return a < 0 || a >= N || b < 0 || b >= N;
}

long long dfs(int x, int y) {
	if (x == N - 1 && y == N - 1) {
		return 1;
	}
	
	if (dp[x][y] == -1) {
		dp[x][y] = 0;

		if (board[x][y] == 0) return 0;

		for (int dir = 0; dir < 2; dir++) {
			int nx = x + board[x][y] * dx[dir];
			int ny = y + board[x][y] * dy[dir];

			if (OOB(nx, ny)) continue;
			dp[x][y] += dfs(nx, ny);
		}
	}

	return dp[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			dp[i][j] = -1;
		}
	}
	dfs(0, 0);

	cout << (dp[0][0] == -1 ? 0 : dp[0][0]);
}