#include <bits/stdc++.h>
using namespace std;

vector<int> parent;

int find(int n) {
	if (parent[n] == n) return n;
	else return parent[n] = find(parent[n]);
}

void merge(int a, int b) {
	a = find(a);
	b = find(b);

	if (a == b) return;
	else parent[a] = b;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	parent.resize(n+1);
	
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}

	int ans = 0;

	for (int i = 0; i < m; i++) {
		int s, e;
		cin >> s >> e;
		if (find(s) == find(e)) {
			ans = i + 1;
			break;
		}
		else {
			merge(s, e);
		}
	}

	cout << ans;
}