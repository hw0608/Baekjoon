#include <bits/stdc++.h>
using namespace std;

int arr[1001];
int l[1001];
int r[1001];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i--) {
		r[i] = 1;
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[i] && r[i] <= r[j]) r[i] = r[j] + 1;
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		l[i] = 1;

		for (int j = 0; j < i; j++) {
			if (arr[j] < arr[i] && l[i] <= l[j]) l[i] = l[j] + 1;
		}
		ans = max(ans, l[i] + r[i] - 1);
	}

	cout << ans;
}