#include <iostream>
#include <stack>
#include <string>

using namespace std;


int main() {
	int num;
	stack<int> sta;
	cin >> num;
	string order;
	for (int i = 0; i < num; i++) {
		cin >> order;
		if (order == "push") {
			int num2;
			cin >> num2;
			sta.push(num2);
		}
		else if (order == "pop") {
			if (!sta.size())
				cout << "-1" << endl;
			else {
				cout << sta.top() << endl;
				sta.pop();
			}
		}
		else if (order == "size")
			cout << sta.size() << endl;
		else if (order == "empty")
			cout << sta.empty() << endl;
		else if (order == "top") {
			if (!sta.empty())
				cout << sta.top() << endl;
			else
				cout << "-1" << endl;
		}

	}
	return 0;

}