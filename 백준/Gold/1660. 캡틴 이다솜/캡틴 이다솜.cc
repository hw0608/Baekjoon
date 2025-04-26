#include <bits/stdc++.h>
using namespace std;

int triangle[121];
int tetrahedron[121];

int dp[300001];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	triangle[1] = 1;
	tetrahedron[1] = 1;

	fill(&dp[0], &dp[N + 1], -1);
	dp[0] = 0;

	for (int i = 2; i <= 120; i++) {
		triangle[i] = triangle[i - 1] + i;
	}

	for (int i = 2; i <= 120; i++) {
		tetrahedron[i] = tetrahedron[i - 1] + triangle[i];
		dp[tetrahedron[i]] = 1;
	}


	for (int i = 1; i <= 120; i++) {
		for (int j = 1; j <= N; j++) {
			if (j - tetrahedron[i] < 0 || dp[j - tetrahedron[i]] == -1) continue;
			if (dp[j] == -1) dp[j] = dp[j - tetrahedron[i]] + 1;
			dp[j] = min(dp[j], dp[j - tetrahedron[i]] + 1);
		}
	}

	cout << dp[N];
}