#include <bits/stdc++.h>
using namespace std;

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int N;
char board[27][27];
bool visited[27][27];

bool OOB(int a, int b) {
	return a < 0 || a >= N || b < 0 || b >= N;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> board[i][j];
		}
	}

	queue<pair<int, int>> q;

	int num = 1;
	vector<int> ans;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (board[i][j] == '0' || visited[i][j]) continue;

			q.push({ i, j });
			visited[i][j] = true;

			int area = 1;

			while (!q.empty()) {
				auto cur = q.front(); q.pop();

				for (int dir = 0; dir < 4; dir++) {
					int nx = cur.first + dx[dir];
					int ny = cur.second + dy[dir];

					if (OOB(nx, ny) || board[nx][ny] == '0' || visited[nx][ny]) continue;
					visited[nx][ny] = true;
					q.push({ nx,ny });
					area++;
				}
			}
			num++;
			ans.push_back(area);
		}
	}

	cout << ans.size() << '\n';

	sort(ans.begin(), ans.end());

	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << '\n';
	}
}