#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int findRoot(int node) {
	if (root[node] == -1 || root[node] == node) return node;
	else return root[node] = findRoot(root[node]);
}

void unionTree(int x, int y) {
	x = findRoot(x);
	y = findRoot(y);

	if (x != y) {
		root[x] = y;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	root.resize(n + 1);
	fill(root.begin(), root.end(), -1);

	for (int i = 0; i < m; i++) {
		int command, a, b;
		cin >> command >> a >> b;

		if (command == 0) {
			unionTree(a, b);
		}
		else if (command == 1) {
			if (a == b) cout << "YES\n";

			else {
				if (findRoot(a) == findRoot(b)) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
	}
}