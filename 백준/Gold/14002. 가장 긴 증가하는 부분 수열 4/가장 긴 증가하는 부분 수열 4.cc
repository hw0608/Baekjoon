#include <bits/stdc++.h>
using namespace std;

int A[1002];
vector<int> LIS;
int pos[1002];

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (LIS.empty()) {
			LIS.push_back(A[i]);
			pos[i] = 0;
		}
		else {
			if (LIS.back() < A[i]) {
				LIS.push_back(A[i]);
				pos[i] = LIS.size() - 1;
			}
			else {
				int idx = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
				LIS[idx] = A[i];
				pos[i] = idx;
			}
		}
	}

	int len = LIS.size();
	cout << len << '\n';
	int target = len - 1;

	stack<int> result;

	for (int i = N - 1; i >= 0; i--) {
		if (pos[i] == target) {
			result.push(A[i]);
			target--;
		}
	}

	while (!result.empty()) {
		cout << result.top() << " ";
		result.pop();
	}
}