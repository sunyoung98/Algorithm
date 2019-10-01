#include <iostream>

using namespace std;

int main() {
	char input[501];
	cin >> input;
	for (int i = 0; i < strlen(input); i++) {
		if (input[i] == 'X') {
			if (input[i+1]=='X'&&input[i + 2] == 'X' && input[i + 3] == 'X') {
				input[i] = 'A';
				input[i + 1] = 'A';
				input[i + 2] = 'A';
				input[i + 3] = 'A';
				i += 3;
			}
			else if(input[i+1]=='X'){
				input[i] = 'B';
				input[i + 1] = 'B';
				i  += 1;
			}
			else {
				cout << -1;
				return 0;
			}
		}
	}
	cout << input;


}