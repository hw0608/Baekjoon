#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<pair<int, int>> arr(N);

	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x,y };
	}

	sort(arr.begin(), arr.end());

	long long ans = 0;

	int idx = 0;

	while (idx < N) {
		int cursor = idx;
		int tmp = -1000000001;

		while (cursor < N && (arr[cursor].first <= arr[idx].second || arr[cursor].first <= tmp)) {
			tmp = max(tmp, arr[cursor].second);
			cursor++;
		}

		ans += tmp - arr[idx].first;
		idx = cursor;
	}

	cout << ans;
}