#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> universe;
vector<vector<int>> sorted;

map<string, int> str;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int M, N;
	cin >> M >> N;

	for (int i = 0; i < M; i++) {
		vector<int> v;
		for (int j = 0; j < N; j++) {
			int n;
			cin >> n;

			v.push_back(n);
		}
		universe.push_back(v);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		sorted.push_back(v);
	}

	for (int i = 0; i < M; i++) {
		string tmp = "";
		for (int j = 0; j < N; j++) {
			tmp += to_string(lower_bound(sorted[i].begin(), sorted[i].end(), universe[i][j]) - sorted[i].begin());
		}
		str[tmp]++;
	}

	int ans = 0;

	for (auto it = str.begin(); it != str.end(); it++) {
		if (it->second > 1) {
			int cnt = it->second;
			ans += (cnt * (cnt - 1)) / 2;
		}
	}

	cout << ans;
}