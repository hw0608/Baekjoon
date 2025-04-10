#include <bits/stdc++.h>
using namespace std;

int num[1005];
int ans[1005];

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < N; i++) {
        ans[i] = 1;

        for (int j = 0; j < i; j++) {
            if (num[j] < num[i] && ans[i] <= ans[j]) ans[i] = ans[j] + 1;
        }
    }
    sort(ans, ans + N, greater<>());
    cout << ans[0];
}