#include <bits/stdc++.h>
using namespace std;

int arr[200005];
int cnt[100005];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int e = 0;

	int ans = 0;

	for (int s = 0; s < N; s++) {
		while (cnt[arr[e]] < K && e < N) {
			cnt[arr[e]]++;
			e++;
		}
		ans = max(ans, e - s);
		if (e == N) break;
		cnt[arr[s]]--;
	}

	cout << ans;
}