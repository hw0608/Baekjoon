#include <bits/stdc++.h>
using namespace std;

vector<bool> isNotPrime;
vector<int> primes;

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N, ans = 0;
	cin >> N;

	isNotPrime.resize(N + 1);

	for (int i = 2; i * i <= N; i++) {
		if (!isNotPrime[i]) {
			for (int j = 2; j * i <= N; j++) {
				isNotPrime[j * i] = true;
			}
		}
	}

	for (int i = 2; i <= N; i++) {
		if (!isNotPrime[i]) {
			primes.push_back(i);
		}
	}

	int start = 0, end = 0, sum = 0;

	while (true) {
		if (sum > N) {
			sum -= primes[start++];
		}
		else if (end == primes.size()) break;
		else
			sum += primes[end++];

		if (sum == N) ans++;
	}

	cout << ans;
}