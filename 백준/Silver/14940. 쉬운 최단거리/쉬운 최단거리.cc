#include <bits/stdc++.h>
using namespace std;

int n, m;
int board[1002][1002];
int dist[1002][1002];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int a, int b) {
	return a < 0 || a >= n || b < 0 || b >= m;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> n >> m;
	queue<pair<int, int>> q;
	fill(&dist[0][0], &dist[1001][1002], -1);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			if (board[i][j] == 2) {
				dist[i][j] = 0;
				q.push({ i,j });
			}
		}
	}

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (OOB(nx, ny) || board[nx][ny] != 1 || dist[nx][ny] != -1) continue;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
			q.push({ nx,ny });
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 0) {
				cout << 0 << " ";
			}
			else {
				cout << dist[i][j] << " ";
			}
		}
		cout << '\n';
	}
}