#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n, n1, n2;
	int sum = 0;
	bool zero = false;
	cin >> n;
	vector<int> pos;
	vector<int> neg;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (num == 1)
			sum++;
		else if (num > 1)
			pos.push_back(num);
		else if (num < 0)
			neg.push_back(num);
		else
			zero = true;
	}
	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	if (pos.size() % 2) {
		sum += pos.front();
		pos.erase(pos.begin());
	}
	while (!pos.empty()) {
		n1 = pos.back();
		pos.pop_back();
		n2 = pos.back();
		pos.pop_back();
		sum += n1 * n2;
	}
	if (neg.size() % 2) {
		if (zero)
			neg.pop_back();
		else {
			n1 = neg.back();
			neg.pop_back();
			sum += n1;
		}
	}
	while (!neg.empty()) {
		n1 = neg.back();
		neg.pop_back();
		n2 = neg.back();
		neg.pop_back();
		sum += n1 * n2;
	}
	cout << sum << endl;
	return 0;
}