#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;


int main() {
	const int MAX = 300000;
	int N, K, index = 0;
	long long sum = 0;
	int bag[MAX];
	pair<int, int> je[MAX];
	priority_queue<int> pq;
	cin >> N >> K;
	cin.tie(0);
	for (int i = 0; i < N; i++)
		cin >> je[i].first >> je[i].second;
	for (int i = 0; i < K; i++)
		cin >> bag[i];
	sort(je, je + N);
	sort(bag, bag + K);
	for (int i = 0; i < K; i++) {
		while (index < N&&je[index].first <= bag[i]) {
			pq.push(je[index].second);
			++index;
		}
		if (!pq.empty()) {
			sum += pq.top();
			pq.pop();
		}

	}
	cout << sum;
	return 0;
}
