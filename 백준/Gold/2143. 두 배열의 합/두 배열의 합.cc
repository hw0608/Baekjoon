#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int A[1001];
int prefixSum_A[1001];
int B[1001];
int prefixSum_B[1001];

unordered_map<int, long long> a;
unordered_map<int, long long> b;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int T, n, m;
	long long ans = 0;

	cin >> T >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];

		if (i == 0)
		{
			prefixSum_A[i] = A[i];
		}
		else
		{
			prefixSum_A[i] = prefixSum_A[i - 1] + A[i];

			for (int j = 0; j < i; j++) {
				int s = prefixSum_A[i] - prefixSum_A[j];
				a[s]++;
			}
		}
		a[prefixSum_A[i]]++;
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> B[i];
		if (i == 0)
		{
			prefixSum_B[i] = B[i];
		}
		else
		{
			prefixSum_B[i] = prefixSum_B[i - 1] + B[i];
			for (int j = 0; j < i; j++) {
				int s = prefixSum_B[i] - prefixSum_B[j];
				b[s]++;
			}
		}
		b[prefixSum_B[i]]++;
	}

	for (auto it = a.begin(); it != a.end(); it++) {
		int num_A = it->first;
		int num_B = T - num_A;

		ans += it->second * b[num_B];
	}

	cout << ans;
}