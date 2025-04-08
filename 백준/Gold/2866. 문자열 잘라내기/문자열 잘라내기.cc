#include <bits/stdc++.h>
using namespace std;

char table[1005][1005];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int R, C;
	cin >> R >> C;

	vector<string> str(C+1);
	fill(str.begin(), str.end(), "");

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> table[i][j];
			str[j] = table[i][j] + str[j];
		}
	}

	sort(str.begin(), str.end());

	int ans = 0;

	for (int i = 1; i < str.size() - 1; i++) {
		int len = 0;
		for (int j = 0; j < str[i].size(); j++) {
			if (str[i][j] == str[i + 1][j]) len++;
			else break;
		}
		ans = max(len, ans);
	}
	
	cout << R - ans - 1;
}