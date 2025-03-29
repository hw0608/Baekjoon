#include <bits/stdc++.h>
using namespace std;

int I, N, K;
string ink;
char grid[105][105];
pair<int, int> pos;
int amount = 0;
int jumpIdx = 0;

bool OOB(int x, int y) {
	return x < 0 || x >= N || y < 0 || y >= N;
}

void move(char command) {
	int nx = pos.first;
	int ny = pos.second;

	switch (command)
	{
	case 'U': nx -= 1; break;
	case 'D': nx += 1; break;
	case 'L': ny -= 1; break;
	case 'R': ny += 1; break;
	}

	if (OOB(nx, ny) || grid[nx][ny] != '.') return;
	grid[nx][ny] = '@';
	grid[pos.first][pos.second] = '.';

	pos = { nx,ny };
}

void spread(char currentInk) {
	for (int i = pos.first - amount; i <= pos.first + amount; i++) {
		for (int j = pos.second - amount; j <= pos.second + amount; j++) {
			if (OOB(i, j)) continue;
			int dist = abs(i - pos.first) + abs(j - pos.second);
			if (grid[i][j] != '.' && grid[i][j] != '@' && dist <= amount) {
				grid[i][j] = currentInk;
			}
		}
	}

	amount = 0;
}

int main(void) {
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	cin >> I >> N >> K;
	cin >> ink;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == '@') {
				pos = { i,j };
			}
		}
	}

	for (int i = 0; i < K; i++) {
		char command;
		cin >> command;

		switch (command)
		{
		case 'U':
		case 'D':
		case 'L':
		case 'R': move(command); break;
		case 'j': amount++; break;
		case 'J': 
			char currentInk = ink[jumpIdx]; 
			jumpIdx = (jumpIdx + 1) % ink.length();
			spread(currentInk);
			break;
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << grid[i][j];
		}
		cout << '\n';
	}
}