#include <bits/stdc++.h>
using namespace std;

int N;
int num[15];
int oper[4];
int isused[4];
int arr[15];
const int INF = (~0U >> 2);

int minAns = INF;
int maxAns = INF*-1;

void func(int k) {
    if (k == N - 1) {
        queue<int> q;

        for (int i = 1; i <= N; i++) {
            q.push(num[i]);
        }

        int cal = q.front(); q.pop();

        for (int i = 0; i < N - 1; i++) {
            if (arr[i] == 0) {
                cal += q.front();
                q.pop();
            }
            else if (arr[i] == 1) {
                cal -= q.front();
                q.pop();
            }
            else if (arr[i] == 2) {
                cal *= q.front();
                q.pop();
            }
            else if (arr[i] == 3) {
                cal /= q.front();
                q.pop();
            }
        }

        minAns = min(minAns, cal);
        maxAns = max(maxAns, cal);

        return;
    }

    for (int i = 0; i < 4; i++) {
        if (isused[i] == 0) continue;
        isused[i]--;
        arr[k] = i;
        func(k + 1);
        isused[i]++;
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    for (int i = 1; i <= N; i++)
        cin >> num[i];

    for (int i = 0; i < 4; i++) {
        int tmp;
        cin >> tmp;
        oper[i] = tmp;
        isused[i] = tmp;
    }

    func(0);

    cout << maxAns << '\n' << minAns;
}