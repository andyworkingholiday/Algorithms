#include <iostream>
#include <queue>
using namespace std;

int N, M, answer;

int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		answer = 0;
		queue<pair<int, int>> q;
		priority_queue<int> pq;
		scanf("%d %d", &N, &M);
		int item;
		for (int i = 0; i < N; i++) {
			scanf("%d", &item);
			q.push(pair<int, int>(i, item));
			pq.push(item);
		}
		while (!q.empty()) {
			int index = q.front().first;
			int value = q.front().second;
			q.pop();
			if (pq.top() == value) {
				pq.pop();
				answer++;
				if (index == M) {
					printf("%d\n", answer);
					break;
				}
			}
			else
				q.push(pair<int, int>(index, value));
		}
	}
}