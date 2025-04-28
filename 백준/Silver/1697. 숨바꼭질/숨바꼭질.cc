#include <bits/stdc++.h>
using namespace std;

int N, K;
int cost[100005];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> K;

	fill(&cost[0], &cost[100005], -1);
	cost[N] = 0;
	queue<int> q;
	q.push(N);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		if (cur == K) {
			cout << cost[K];
			return 0;
		}

		if (cur + 1 <= 100000 && cost[cur + 1] == -1) {
			cost[cur + 1] = cost[cur] + 1;
			q.push(cur + 1);
		}
		if (cur - 1 >= 0 && cost[cur - 1] == -1) {
			cost[cur - 1] = cost[cur] + 1;
			q.push(cur - 1);
		}
		if (cur * 2 <= 100000 && cost[cur * 2] == -1) {
			cost[cur * 2] = cost[cur] + 1;
			q.push(cur * 2);
		}
	}
}