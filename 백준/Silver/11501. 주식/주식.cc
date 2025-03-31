#include <bits/stdc++.h>
using namespace std;

int input[1000005];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N; i++) {
			cin >> input[i];
		}

		stack<int> st;
		long long ans = 0;

		for (int i = N - 1; i >= 0; i--) {
			if (st.empty()) {
				st.push(i);
			}
			else {
				if (input[i] >= input[st.top()]) {
					st.pop();
					st.push(i);
				}
				else {
					ans += input[st.top()] - input[i];
				}
			}
		}

		cout << ans << '\n';
	}
}