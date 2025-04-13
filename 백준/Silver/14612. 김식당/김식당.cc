#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<pair<int, int>> v;

	for (int i = 0; i < N; i++) {
		string command;
		cin >> command;
		if (command == "order") {
			int n, t;
			cin >> n >> t;

			v.push_back({ t,n });
		}
		else if (command == "complete") {
			int n;
			cin >> n;

			for (int i = 0; i < v.size(); i++) {
				if (v[i].second == n) {
					v.erase(v.begin() + i);
					break;
				}
			}
		}
		else {
			sort(v.begin(), v.end());
		}

		for (int i = 0; i < v.size(); i++) {
			cout << v[i].second << " ";
		}

		if (v.empty()) {
			cout << "sleep";
		}

		cout << '\n';
	}
}