#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr;
	vector<int> sorted;
	map<int, int> newIdx;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr.push_back(n);
		sorted.push_back(n);
	}

	sort(sorted.begin(), sorted.end());

	int rank = 0;
	newIdx[sorted[0]] = 0;

	for (int i = 1; i < N; i++) {
		if (sorted[i - 1] != sorted[i]) {
			rank++;
			newIdx[sorted[i]] = rank;
		}
	}

	for (int i = 0; i < N; i++) {
		arr[i] = newIdx[arr[i]];
		cout << arr[i] << ' ';
	}
}