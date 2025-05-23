#include <bits/stdc++.h>
using namespace std;
#define MAX 1e8

vector<pair<int, int>> edges[1002];
int dist[1002];
int parent[1002];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	fill(&dist[0], &dist[1002], MAX);
	fill(&parent[0], &parent[1002], -1);

	for (int i = 0; i < m; i++) {
		int s, e;
		long long c;
		cin >> s >> e >> c;

		edges[s].push_back({ c, e });
	}

	int start, end;
	cin >> start >> end;

	priority_queue<pair<int, int>> pq;

	dist[start] = 0;
	pq.push({ 0, start });

	while (!pq.empty()) {
		auto cur = pq.top(); pq.pop();

		if (dist[cur.second] < -cur.first) continue;

		for (int i = 0; i < edges[cur.second].size(); i++) {
			int nextNode = edges[cur.second][i].second;
			int nextDist = -cur.first + edges[cur.second][i].first;

			if (dist[nextNode] > nextDist) {
				parent[nextNode] = cur.second;
				dist[nextNode] = nextDist;
				pq.push({ -nextDist, nextNode });
			}
		}
	}

	stack<int> path;
	path.push(end);
	
	while (path.top() != start) {
		path.push(parent[path.top()]);
	}

	cout << dist[end] << '\n';
	cout << path.size() << '\n';
	while (!path.empty()) {
		cout << path.top() << " ";
		path.pop();
	}
}