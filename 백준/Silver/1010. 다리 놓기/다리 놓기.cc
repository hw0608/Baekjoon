#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N, M;
		cin >> N >> M;

		long long ans = 1;

		for (int i = M; i > M - N; i--) {
			ans *= i;
			ans /= (M - i + 1);
		}

		cout << ans << '\n';
	}
}