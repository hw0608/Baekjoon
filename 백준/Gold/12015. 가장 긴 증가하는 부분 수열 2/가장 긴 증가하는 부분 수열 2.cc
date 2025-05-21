#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	vector<int> A(N);
	vector<int> LIS;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (int i = 0; i < N; i++) {
		if (LIS.empty() || LIS.back() < A[i]) LIS.push_back(A[i]);
		else {
			int idx = lower_bound(LIS.begin(), LIS.end(), A[i]) - LIS.begin();
			LIS[idx] = A[i];
		}
	}

	cout << LIS.size();
}