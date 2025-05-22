#include <bits/stdc++.h>
using namespace std;

int N, M;
int board[55][55];
int dist[55][55];

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

vector<pair<int, int>> virus;
int arr[12];
bool isUsed[12];

int blank = 0;
int ans = -1;

bool OOB(int a, int b) {
	return a < 0 || a >= N || b < 0 || b >= N;
}

void func(int k) {
	if (k == M) {
		int cnt = 0;

		fill(&dist[0][0], &dist[54][55], -1);

		queue<pair<int, int>> q;

		for (int i = 0; i < M; i++) {
			q.push(virus[arr[i]]);
			dist[virus[arr[i]].first][virus[arr[i]].second] = 0;
		}

		while (!q.empty()) {
			auto cur = q.front(); q.pop();

			for (int dir = 0; dir < 4; dir++) {
				int nx = cur.first + dx[dir];
				int ny = cur.second + dy[dir];

				if (OOB(nx, ny)) continue;
				if (board[nx][ny] == 1 || dist[nx][ny] != -1) continue;
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
				if (board[nx][ny] == 0) cnt++;

				if (cnt == blank) {
					if (ans == -1) ans = dist[nx][ny];
					else ans = min(ans, dist[nx][ny]);

					return;
				}

				q.push({ nx,ny });
			}
		}

		return;
	}

	for (int i = 0; i < virus.size(); i++) {
		if (isUsed[i]) continue;
		if (k != 0 && arr[k - 1] > i) continue;
		isUsed[i] = true;
		arr[k] = i;
		func(k + 1);
		isUsed[i] = false;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
			if (board[i][j] == 0) {
				blank++;
			}
			else if (board[i][j] == 2) {
				virus.push_back({ i,j });
			}
		}
	}

	if (blank == 0) {
		cout << 0;
		return 0;
	}

	func(0);

	cout << ans;
}