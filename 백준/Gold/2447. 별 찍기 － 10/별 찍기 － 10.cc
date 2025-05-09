/* ************************************************************************** */
/*                                                                            */
/*                                                      :::    :::    :::     */
/*   Problem Number: 2447                              :+:    :+:      :+:    */
/*                                                    +:+    +:+        +:+   */
/*   By: 048895 <boj.kr/u/048895>                    +#+    +#+          +#+  */
/*                                                  +#+      +#+        +#+   */
/*   https://boj.kr/2447                           #+#        #+#      #+#    */
/*   Solved: 2025/05/09 15:50:01 by 048895        ###          ###   ##.kr    */
/*                                                                            */
/* ************************************************************************** */
#include <bits/stdc++.h>
using namespace std;

char ans[6565][6565];

void func(int n, int x, int y)
{
	if (n == 1)
	{
		ans[x][y] = '*';
		return;
	}

	int div = n / 3;
	func(div, x, y);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ((i == 0 && j == 0) || (i == 1 && j == 1)) continue;
			for (int di = 0; di < div; di++)
			{
				for (int dj = 0; dj < div; dj++)
				{
					ans[x + i * div + di][y + j * div + dj] = ans[x + di][y + dj];
				}
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	func(N, 1, 1);

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (ans[i][j] != '*') cout << " ";
			else cout << ans[i][j];
		}
		cout << '\n';
	}
}