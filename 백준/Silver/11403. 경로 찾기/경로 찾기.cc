#include <bits/stdc++.h>
using namespace std;

int N;
int graph[105][105];
int dist[105][105];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dist[i][j] = INT_MAX / 2;
			cin >> graph[i][j];
			if (graph[i][j])
				dist[i][j] = 1;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dist[i][j] < INT_MAX / 2) {
				cout << 1 << " ";
			}
			else {
				cout << 0 << " ";
			}
		}
		cout << '\n';
	}
}