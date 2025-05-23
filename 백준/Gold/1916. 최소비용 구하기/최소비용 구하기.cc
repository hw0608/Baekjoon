#include <bits/stdc++.h>
using namespace std;
#define INF ~0U >> 2

int N, M;
int cost[1005][1005];
int ans[1005];
bool visited[1005];

int findNode() {
    int minDist = INF, minIdx = -1;

    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        if (ans[i] < minDist) {
            minDist = ans[i];
            minIdx = i;
        }
    }

    return minIdx;
}

void update(int node) {
    for (int i = 1; i <= N; i++) {
        if (visited[i]) continue;
        if (ans[i] > ans[node] + cost[node][i])
            ans[i] = ans[node] + cost[node][i];
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    
    cin >> N >> M;

    fill(&cost[0][0], &cost[1004][1005], INF);
    fill(&ans[0], &ans[1005], INF);

    for (int i = 0; i < M; i++) {
        int x, y, fee;
        cin >> x >> y >> fee;
        if (fee < cost[x][y])
            cost[x][y] = fee;
    }

    int start, des;
    cin >> start >> des;

    for (int i = 1; i <= N; i++) {
        ans[i] = cost[start][i];
    }

    ans[start] = 0;
    visited[start] = true;

    for (int i = 0; i < N - 1; i++) {
        int node = findNode();
        visited[node] = true;
        update(node);
    }

    cout << ans[des];
}