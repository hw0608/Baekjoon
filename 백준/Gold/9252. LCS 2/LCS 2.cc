#include <bits/stdc++.h>
using namespace std;

int dp[1002][1002];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	string str1, str2;
	cin >> str1 >> str2;

	str1 = "." + str1;
	str2 = "." + str2;

	for (int i = 0; i < str1.size(); i++) {
		for (int j = 0; j < str2.size(); j++) {
			if (i == 0 || j == 0) continue;
			else if (str1[i] == str2[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else {
				if (dp[i - 1][j] > dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];

				}
				else {
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
	}

	cout << dp[str1.size() - 1][str2.size() - 1] << '\n';

	int n = str1.size() - 1;
	int m = str2.size() - 1;

	stack<char> st;

	while (n > 0 && m > 0) {
		if (str1[n] == str2[m]) {
			st.push(str2[m]);
			n--;
			m--;
		}
		else if (dp[n - 1][m] > dp[n][m - 1]) {
			n--;
		}
		else {
			m--;
		}
	}

	while (!st.empty()) {
		cout << st.top();
		st.pop();
	}
}