#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

int map[21][21];
int num;
int sum = 0;
int i, j, k;
bool floyd[21][21];
int main() {
	cin >> num;
	memset(floyd, true, sizeof(floyd));
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++)
			cin >> map[i][j];
	}
	for (k = 0; k < num; k++) { //거쳐가는 노드
		for (i = 0; i < num; i++) { //출발 노드
			for (j = 0; j < num; j++) { //도착 노드
				if (i == j || j == k || k == i)
					continue;
				if (map[i][j] > map[i][k] + map[k][j]) {
					cout << -1 << endl;
					return 0;
				}
				else if (map[i][j] == map[i][k] + map[k][j])
					floyd[i][j] = false;
			}
		}	
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < num; j++) {
			if (floyd[i][j])
				sum += map[i][j];
		}
	}
	cout << sum / 2 << endl;
	
}