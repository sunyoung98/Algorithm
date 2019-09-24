#include <iostream>
#include <string>
#include <vector>
using namespace std;
int n;
vector<string> ch;
int c1, c2, i;
string s;
int main() {
	cin >> n;
	for (i = 1; i <=n; i++) {
		cin >> s;
		if (s=="KBS1")
			c1 = i;
		if (s=="KBS2")
			c2 = i;
		ch.push_back(s);
	}
	if (c1 > c2)
		c2 += 1;
	for (i = 1; i < c1; i++)
		cout << 1;
	for (i = 1; i <c1; i++)
		cout << 4;
	for (i = 1; i <c2; i++)
		cout << 1;
	for (i = 1; i <c2-1; i++)
		cout << 4;
	return 0;
}