#include <bits/stdc++.h>
using namespace std;

int M, N;
int height[505][505];
int dp[505][505];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int x, int y) {
	return x <= 0 || x > M || y <= 0 || y > N;
}

int DFS(int x, int y) {
	if (x == M && y == N) {
		return 1;
	}

	if (dp[x][y] == -1) {
		dp[x][y] = 0;
		for (int dir = 0; dir < 4; dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (OOB(nx, ny)) continue;
			if (height[x][y] <= height[nx][ny]) continue;
			dp[x][y] += DFS(nx, ny);
		}
	}

	return dp[x][y];
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> M >> N;

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> height[i][j];
			dp[i][j] = -1;
		}
	}

	cout << DFS(1, 1);
}