#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> position(N);

	for (int i = 0; i < N; i++) {
		cin >> position[i];
	}

	sort(position.begin(), position.end());

	int low = 0;
	int high = position.back() - position.front();

	int ans = 0;

	while (low <= high) {
		int mid = (low + high) / 2;

		int cnt = 1;
		int lastRouter = position[0];

		for (int i = 1; i < N; i++) {
			if (position[i] - lastRouter >= mid) {
				lastRouter = position[i];
				cnt++;
			}
		}

		if (cnt >= C) {
			low = mid + 1;
			ans = max(ans, mid);
		}
		else {
			high = mid - 1;
		}
	}

	cout << ans;
}