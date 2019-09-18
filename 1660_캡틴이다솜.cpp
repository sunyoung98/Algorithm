#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int Min(int a, int b) {
	return a < b ? a : b;
}
const int INF = INT_MAX;
int main() {
	int num;
	vector<int> canon;
	int dp[300001];
	cin >> num;
	canon.push_back(0);
	for (int i = 1; i <= num; i++) {
		if (canon[i-1]+i*(i + 1) / 2 <= num) 
			canon.push_back(canon[i - 1] + i * (i + 1) / 2);
		else
			break;
	}
	for (int i = 0; i <= num; ++i)
		dp[i] = INF;
	dp[0] = 0;
	for (int i = 1; i < canon.size(); i++)
		dp[canon[i]] = 1;
	for(int i=1; i<canon.size();i++)
		for (int j = canon[i]; j <= num; j++)
			dp[j] = Min(dp[j], dp[j - canon[i]] + 1);

	if (dp[num] == INF) cout <<-1<<endl;
	else
		cout << dp[num];
	return 0;
}