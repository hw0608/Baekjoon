#include <bits/stdc++.h>
using namespace std;
#define INF 1000000

int dist[20001];
vector<pair<int, int>> edge[300001];

void dijkstra(int s) {
	dist[s] = 0;

	priority_queue<pair<int, int>> pq;

	pq.push({ 0, s });

	while (!pq.empty()) {
		int distance = -pq.top().first;
		int currentNode = pq.top().second;
		pq.pop();

		if (dist[currentNode] < distance) continue;

		for (int i = 0; i < edge[currentNode].size(); i++) {
			int next = edge[currentNode][i].second;
			int nextDistance = distance + edge[currentNode][i].first;

			if (dist[next] > nextDistance) {
				dist[next] = nextDistance;

				pq.push({ -nextDistance, next });
			}
		}
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int V, E;
	cin >> V >> E;

	int K;
	cin >> K;

	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}

	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;

		edge[u].push_back({ w, v });
	}

	dijkstra(K);

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dist[i] << '\n';
		}
	}
}