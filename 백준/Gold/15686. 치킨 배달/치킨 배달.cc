#include <bits/stdc++.h>
using namespace std;

int N, M;
int city[52][52];
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;

int dist[102][15];
int arr[15];
bool isUsed[15];

int ans = 0;

void func(int k) {
	if (k == M) {
		int chickenDistance = 0;

		for (int i = 0; i < house.size(); i++) {
			int tmp = 10000;
			for (int j = 0; j < M; j++) {
				tmp = min(tmp, dist[i][arr[j]]);
			}
			chickenDistance += tmp;
		}

		if (ans == 0) ans = chickenDistance;
		else ans = min(ans, chickenDistance);

		return;
	}

	for (int i = 0; i < chicken.size(); i++) {
		if (isUsed[i]) continue;
		if (k != 0 && arr[k - 1] > i) continue;
		isUsed[i] = true;
		arr[k] = i;
		func(k + 1);
		isUsed[i] = false;
	}
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> city[i][j];
			if (city[i][j] == 1) {
				house.push_back({ i,j });
			}
			else if (city[i][j] == 2) {
				chicken.push_back({ i,j });
			}
		}
	}

	for (int i = 0; i < house.size(); i++) {
		for (int j = 0; j < chicken.size(); j++) {
			dist[i][j] = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
		}
	}

	func(0);

	cout << ans;
}