#include <bits/stdc++.h>
using namespace std;

int N, M;
char maze[105][105];
int dist[105][105];
bool visited[105][105];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int x, int y) {
	return x <= 0 || x > N || y <= 0 || y > M;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> maze[i][j];
		}
	}

	queue<pair<int, int>> q;

	q.push({ 1,1 });
	dist[1][1] = 1;

	while (!q.empty()) {
		auto cur = q.front(); q.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (OOB(nx, ny) || visited[nx][ny] || maze[nx][ny] == '0') continue;

			if (nx == N && ny == M) {
				cout << dist[cur.first][cur.second] + 1;
				return 0;
			}

			q.push({ nx,ny });
			visited[nx][ny] = true;
			dist[nx][ny] = dist[cur.first][cur.second] + 1;
		}
	}
}