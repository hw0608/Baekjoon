#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	int ans = 0;

	while (N--) {
		stack<int> st[30];
		bool flag = true;

		string str;
		cin >> str;

		for (int i = 0; i < str.size(); i++) {
			int idx = str[i] - 'a';
			if (st[idx].empty()) {
				st[idx].push(i);
			}
			else {
				int diff = i - st[idx].top();
				if (diff > 1) {
					flag = false;
					break;
				}
				st[idx].push(i);
			}
		}

		if (flag) ans++;
	}

	cout << ans;
}