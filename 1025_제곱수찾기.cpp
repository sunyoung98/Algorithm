#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>

using namespace std;

char MAP[10][10];
int N, M;
int MAX = -1;

void solve(int sum) {
	if ((int)sqrt(sum) == sqrt(sum)) {
		if (MAX < sum)
			MAX = sum;
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> MAP[i];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int x = -M; x < M; x++) {
				for (int y = -N; y < N; y++) {
					int sum = 0;
					int cur = 0;

					if (x == 0 && y == 0)
						continue;
					while (true) {
						int ypos = i + cur * y;
						int xpos = j + cur * x;
						if (ypos >= 0 && ypos < N && xpos >= 0 && xpos < M) {
							sum = (sum * 10) + (MAP[ypos][xpos] - '0');
							cur++;
							solve(sum);
						}
						else
							break;

					}
				}
			}
		}
	}
	cout << MAX;
	return 0;
}