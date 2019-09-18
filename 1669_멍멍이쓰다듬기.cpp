#include <iostream>
#include <math.h>
using namespace std;

int main() {
	int dog, mon, n;
	double i;
	cin >> mon >> dog;
	n = dog - mon;
	if (n <= 2) {
		cout << n;
		return 0;
	}
	i = sqrt((double)n);
	if ((i - (int)i) != 0)
		i = (int)i + 1;

	if (i*i - i < n)
		cout << i * 2 - 1;
	else
		cout << i * 2 - 2;
	return 0;
}