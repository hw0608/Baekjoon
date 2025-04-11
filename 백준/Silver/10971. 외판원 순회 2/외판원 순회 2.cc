#include <bits/stdc++.h>
using namespace std;
#define INF ~0U>>2

int N;
int cost[12][12];
int arr[12];
bool isUsed[12];

int ans = INF;

void func(int k) {
	if (k == N) {

		int sum = 0;

		for (int i = 1; i < N; i++) {
			if (cost[arr[i - 1]][arr[i]] == 0) {
				return;
			}
			sum += cost[arr[i - 1]][arr[i]];
		}
		if (cost[arr[N - 1]][arr[0]] == 0) return;
		sum += cost[arr[N - 1]][arr[0]];
		ans = min(ans, sum);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (isUsed[i]) continue;
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

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}

	func(0);

	cout << ans;
}