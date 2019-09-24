#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

char alpha[15];
int L, C;
void solve(int mo, int ja, int index, string pw) {
	if (pw.length() == L && mo >= 1 && ja >= 2) {
		cout << pw << endl;
		return;
	}
	if (index == C) return;
	if (alpha[index] == 'a' || alpha[index] == 'e' || alpha[index] == 'i' || alpha[index] == 'o' || alpha[index] == 'u')
		solve(mo + 1, ja, index + 1, pw + alpha[index]);
	else
		solve(mo, ja + 1, index + 1, pw + alpha[index]);
	solve(mo, ja, index + 1, pw);
}

int main() {

	cin >> L >> C;
	for (int i = 0; i < C; i++)
		cin >> alpha[i];
	sort(alpha, alpha + C);
	solve(0, 0, 0, "");
	return 0;
}