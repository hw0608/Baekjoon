#include <bits/stdc++.h>
using namespace std;

int nums[2005];
bool dp[2005][2005];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> nums[i];
		dp[i][i] = true;
	}

	for (int i = 2; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			if (nums[j - i + 1] == nums[j] && (i==2 || dp[j - i + 2][j - 1])) {
				dp[j - i + 1][j] = true;
			}
		}
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; i++) {
		int S, E;
		cin >> S >> E;

		cout << dp[S][E] << '\n';
	}
}