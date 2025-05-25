#include <bits/stdc++.h>
using namespace std;

int R, C, M;
int board[102][102];
int tmp[102][102];

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,1,-1 };

struct Shark {
	int r, c, s, d, z;
};

vector<Shark> shark;
int ans = 0;

void Fishing(int col) {
	for (int i = 1; i <= R; i++) {
		if (board[i][col] != -1) {
			ans += shark[board[i][col]].z;
			shark[board[i][col]].z = 0;
			board[i][col] = -1;
			break;
		}
	}
}

void Move() {
	fill(&tmp[0][0], &tmp[101][102], -1);

	for (int i = 0; i < shark.size(); i++) {
		Shark current = shark[i];
		if (current.z == 0) continue;

		int speed = current.s;
		int dir = current.d;
		int x = current.r;
		int y = current.c;

		while (speed--) {
			x += dx[dir];
			y += dy[dir];

			if (x <= 0) {
				dir = 2;
				x = 2;
			}
			else if (x > R) {
				dir = 1;
				x = R - 1;
			}
			else if (y <= 0) {
				dir = 3;
				y = 2;
			}
			else if (y > C) {
				dir = 4;
				y = C - 1;
			}
		}

		shark[i].r = x;
		shark[i].c = y;
		shark[i].d = dir;

		if (tmp[x][y] != -1) {
			if (shark[tmp[x][y]].z > current.z) {
				shark[i].z = 0;
			}
			else {
				shark[tmp[x][y]].z = 0;
				tmp[x][y] = i;
			}
		}
		else {
			tmp[x][y] = i;
		}
	}

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			board[i][j] = tmp[i][j];
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> R >> C >> M;
	int r, c, s, d, z;

	fill(&board[0][0], &board[101][102], -1);

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		if (d == 1 || d == 2) { s %= ((R - 1) * 2); }
		else { s %= ((C - 1) * 2); }
		shark.push_back({ r, c, s, d, z });

		board[r][c] = i;
	}

	for (int i = 1; i <= C; i++) {
		Fishing(i);
		Move();
	}

	cout << ans;
}