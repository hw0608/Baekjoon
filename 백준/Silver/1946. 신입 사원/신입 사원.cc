#include <bits/stdc++.h>
using namespace std;

int ranking[100002];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T, N;
	cin >> T;

	while (T--) {
		cin >> N;

		for (int i = 0; i < N; i++) {
			int resume, interview;
			cin >> resume >> interview;

			ranking[resume] = interview;
		}

		int ans = 1, cur = 1;

		for (int i = 2; i <= N; i++) {
			if (ranking[cur] > ranking[i]) {
				cur = i;
				ans++;
			}
		}
		
		cout << ans << '\n';
	}
}