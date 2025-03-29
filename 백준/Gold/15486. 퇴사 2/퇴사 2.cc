#include <bits/stdc++.h>
using namespace std;

int dp[1500005];
int t[1500001];
int p[1500001];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> t[i] >> p[i];
	}

	for (int i = N; i >= 1; i--) {
		if (i + t[i] > N + 1) {
			dp[i] = dp[i + 1];
		}
		else {
			dp[i] = max(dp[i + 1], p[i] + dp[i + t[i]]);
		}
	}

	cout << dp[1];
}