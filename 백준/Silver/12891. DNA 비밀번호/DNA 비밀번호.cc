#include <bits/stdc++.h>
using namespace std;

int required[4];
int window[4];

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int S, P;
	cin >> S >> P;

	string dna;
	cin >> dna;

	for (int i = 0; i < 4; i++) {
		cin >> required[i];
	}

	int cnt = 0;
	int answer = 0;

	for (int i = 0; i < dna.length(); i++) {
		cnt++;

		if (dna[i] == 'A') window[0]++;
		else if (dna[i] == 'C') window[1]++;
		else if (dna[i] == 'G') window[2]++;
		else if (dna[i] == 'T') window[3]++;

		if (cnt > P)
		{
			cnt--;
			if (dna[i - P] == 'A') window[0]--;
			else if (dna[i - P] == 'C') window[1]--;
			else if (dna[i - P] == 'G') window[2]--;
			else if (dna[i - P] == 'T') window[3]--;
		}

		if (cnt == P) {
			bool flag = true;
			for (int j = 0; j < 4; j++) {
				if (window[j] < required[j]) {
					flag = false;
					break;
				}
			}

			if (flag) {
				answer++;
			}
		}
	}

	cout << answer;
}