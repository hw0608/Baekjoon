#include <bits/stdc++.h>
using namespace std;

int dist[100001];
int dx[2] = { -1,1 };

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	queue<int> q;
	int N, K;

	fill(dist, dist + 100001, -1);
	cin >> N >> K;

	if (N == K) {
		cout << 0;
		return 0;
	}

	dist[N] = 0;

	q.push(N);

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++) {
			int nx = cur + dx[dir];

			if (nx < 0 || nx > 100001) continue;
			if (dist[nx] >= 0) continue;
			if (nx == K) {
				cout << dist[cur] + 1;
				return 0;
			}
			dist[nx] = dist[cur] + 1;
			q.push(nx);
		}

		if (2 * cur < 0 || 2 * cur > 100001) continue;
		if (dist[2 * cur] >= 0) continue;
		if (2 * cur == K) {
			cout << dist[cur] + 1;
			return 0;
		}
		dist[2 * cur] = dist[cur] + 1;
		q.push(2 * cur);
	}

}