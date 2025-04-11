#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int A, P;
	cin >> A >> P;

	vector<int> arr;
	unordered_map<int, int> m;
	arr.push_back(A);
	m[A] = 0;
	int ans = 0;

	while (true) {
		int tmp = arr.back();

		int n = 0;

		while (tmp != 0) {
			n += pow(tmp % 10, P);
			tmp /= 10;
		}

		if (n == A || m[n]!=0) {
			ans = m[n];
			break;
		}
		m[n] = arr.size();
		arr.push_back(n);
	}
	cout << ans;
}