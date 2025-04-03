#include <bits/stdc++.h>
using namespace std;

int oven[300005];
int pizza[300005];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int D, N;

	cin >> D >> N;

	for (int i = 1; i <= D; i++) {
		cin >> oven[i];

		if (i > 1 && oven[i - 1] < oven[i]) {
			oven[i] = oven[i - 1];
		}
	}

	for (int i = 1; i <= N; i++) {
		cin >> pizza[i];
	}
	
	int idx = 1;

	for (int i = D; i > 0; i--) {
		if (oven[i] >= pizza[idx]) {
			if (idx == N) {
				cout << i;
				return 0;
			}
			idx++;
		}
	}

	cout << 0;
}