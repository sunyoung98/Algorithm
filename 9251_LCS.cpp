#include <iostream>
#include <string>

using namespace std;

string str1, str2;
int map[1001][1001];


void LCS() {
	for (int i = 0; i < str1.size(); i++)
		map[i][0] = 0;
	for (int i = 0; i < str2.size(); i++)
		map[0][i] = 0;
	for (int i = 1; i <= str1.size(); i++) {
		for (int j = 1; j <= str2.size(); j++) {
			if (str1[i] == str2[j])
				map[i][j] = map[i - 1][j - 1] + 1;
			else
				map[i][j] = map[i - 1][j] > map[i][j - 1] ? map[i - 1][j] : map[i][j - 1];
		}
	}
}
int main() {
	string temp1, temp2;
	cin >> temp1 >> temp2;
	str1 = '0' + temp1;
	str2 = '0' + temp2;
	LCS();
	cout << map[str1.size() - 1][str2.size() - 1];
	return 0;
}