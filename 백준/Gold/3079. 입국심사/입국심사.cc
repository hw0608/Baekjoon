#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	long long N, M;
	cin >> N >> M;
	vector<long long> tk(N);

	for (int i = 0; i < N; i++) {
		cin >> tk[i];
	}

	sort(tk.begin(), tk.end());

	unsigned long long low = 1;
	unsigned long long high = M * tk[N - 1];

	unsigned long long mid;

	unsigned long long ans = 0;

	while (high >= low) {
		mid = (low + high) / 2;

		unsigned long long tmp = 0;

		for (int i = 0; i < tk.size(); i++) {
			tmp += mid / tk[i];
		}

		if (tmp >= M) {
			high = mid - 1;

			if (ans > mid || ans == 0) ans = mid;
		}
		else {
			low = mid + 1;
		}
	}

	cout << ans;
}