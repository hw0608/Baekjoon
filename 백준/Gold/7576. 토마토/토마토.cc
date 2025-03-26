#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int tomato[1005][1005];
int timer[1005][1005];

int M, N;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= M;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> M >> N;

	queue<pair<int, int>> q;

	fill(&timer[0][0], &timer[1004][1005], -1);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> tomato[i][j];
			if (tomato[i][j] == 1) {
				q.push({ i,j });
				timer[i][j] = 0;
			}
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (OOB(nx, ny) || tomato[nx][ny] != 0 || (timer[nx][ny] != -1 && timer[nx][ny] <= timer[cur.first][cur.second] + 1)) continue;
					timer[nx][ny] = timer[nx][ny] == -1 ? timer[cur.first][cur.second] + 1 : min(timer[nx][ny], timer[cur.first][cur.second] + 1);
					q.push({ nx,ny });
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tomato[i][j] != -1 && timer[i][j] == -1) {
				cout << -1;
				return 0;
			}
			ans = max(ans, timer[i][j]);
		}
	}

	cout << ans;
}