#include <bits/stdc++.h>
using namespace std;

int R, C;
char board[1002][1002];
int dist_jihoon[1002][1002];
int dist_fire[1002][1002];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

bool OOB(int  a, int b) {
	return a < 0 || a >= R || b < 0 || b >= C;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	queue<pair<int, int>> q_jihoon;
	queue<pair<int, int>> q_fire;

	fill(&dist_jihoon[0][0], &dist_jihoon[1001][1002], -1);
	fill(&dist_fire[0][0], &dist_fire[1001][1002], -1);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];

			if (board[i][j] == 'J')
			{
				dist_jihoon[i][j] = 0;
				q_jihoon.push({ i,j });
			}
			else if (board[i][j] == 'F')
			{
				dist_fire[i][j] = 0;
				q_fire.push({ i,j });
			}
		}
	}

	while (!q_fire.empty()) {
		auto cur = q_fire.front(); q_fire.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (OOB(nx, ny)) continue;
			if (board[nx][ny] == '#' || dist_fire[nx][ny] != -1) continue;
			dist_fire[nx][ny] = dist_fire[cur.first][cur.second] + 1;
			q_fire.push({ nx,ny });
		}
	}

	while (!q_jihoon.empty()) {
		auto cur = q_jihoon.front(); q_jihoon.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (OOB(nx, ny)) {
				if (dist_fire[cur.first][cur.second] > dist_jihoon[cur.first][cur.second] || dist_fire[cur.first][cur.second] == -1) {
					cout << dist_jihoon[cur.first][cur.second] + 1;
					return 0;
				}
			}

			if (board[nx][ny] == '#' || dist_jihoon[nx][ny] != -1) continue;
			if (dist_fire[nx][ny] != -1 && dist_fire[nx][ny] <= dist_jihoon[cur.first][cur.second] + 1) continue;
			dist_jihoon[nx][ny] = dist_jihoon[cur.first][cur.second] + 1;
			q_jihoon.push({ nx,ny });
		}
	}

	cout << "IMPOSSIBLE";
}