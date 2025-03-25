#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<pair<int, int>> q;
	int T, M, N, K, X, Y;
	cin >> T;

	while (T--) {
		int cnt = 0;
		int board[50][50] = {};
		bool vis[50][50] = {};

		cin >> M >> N >> K;

		while (K--) {
			cin >> X >> Y;
			board[X][Y] = 1;
		}


		for (int i = 0; i < M; i++) {
			for (int j = 0; j < N; j++) {
				if (board[i][j] != 1 || vis[i][j] == 1) continue;  
				cnt++;
				q.push({ i, j }); 
				vis[i][j] = 1; 

				while (!q.empty()) {
					auto cur = q.front(); q.pop();

					for (int dir = 0; dir < 4; dir++) {
						int nx = cur.first + dx[dir];
						int ny = cur.second + dy[dir];

						if (nx < 0 || nx > M - 1 || ny < 0 || ny > N - 1) continue;
						if (board[nx][ny] != 1 || vis[nx][ny] == 1) continue;
						vis[nx][ny] = 1;
						q.push({ nx,ny });
					}
				}
			}
		}
		cout << cnt << '\n';
	}
}