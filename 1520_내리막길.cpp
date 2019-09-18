#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;
int M, N;
int dp[500][500];
int map[500][500];
int posX[4] = { 0,0,-1,1 };
int posY[4] = { 1, -1, 0, 0 };
int solve(int y, int x) {
	if (dp[y][x] != -1)
		return dp[y][x];
	if (x == 0 && y == 0) return 1;
	dp[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int posx = x + posX[i];
		int posy = y + posY[i];
		if (posx >= 0 && posx < N && posy >= 0 && posy < M) {
			if (map[posy][posx] > map[y][x])
				dp[y][x] += solve(posy, posx);
		}
	}
	return dp[y][x];
}
int main() {
	cin >> M >> N;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	memset(dp, -1, sizeof(dp));
	cout << solve(M - 1, N - 1);
	return 0;
}