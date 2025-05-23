#include <bits/stdc++.h>
using namespace std;

char board[1000][1000];
int jDist[1000][1000];
int fDist[1000][1000];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int R, C;
	cin >> R >> C;

	queue<pair<int, int>> jQ;
	queue<pair<int, int>> fQ;
	memset(jDist, -1, sizeof(jDist));
	memset(fDist, -1, sizeof(fDist));
	bool flag = false;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'J') { jQ.push({ i,j }); jDist[i][j] = 0; }
			else if (board[i][j] == 'F') {fQ.push({ i,j }); fDist[i][j] = 0;}
		}
	}

	while (!fQ.empty()) {
		auto cur = fQ.front(); fQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			if (board[nx][ny] == '#' || fDist[nx][ny] >= 0) continue;
			fDist[nx][ny] = fDist[cur.first][cur.second] + 1;
			fQ.push({ nx,ny });
		}
	}

	while (!jQ.empty()) {
		auto cur = jQ.front(); jQ.pop();

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.first + dx[dir];
			int ny = cur.second + dy[dir];

			if (nx < 0 || nx >= R || ny < 0 || ny >= C) {
				cout << jDist[cur.first][cur.second] + 1;
				flag = true;
				break;
			}
			if (board[nx][ny] == '#' || jDist[nx][ny] >= 0) continue;
			if (fDist[nx][ny]!=-1 && fDist[nx][ny] <= jDist[cur.first][cur.second] + 1) continue;
			jDist[nx][ny] = jDist[cur.first][cur.second] + 1;
			jQ.push({ nx, ny });
		}
		if (flag) break;
	}
	if (!flag) cout << "IMPOSSIBLE\n";
}