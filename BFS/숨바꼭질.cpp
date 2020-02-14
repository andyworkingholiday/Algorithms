#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;

int N, K;
int visit[MAX];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == K) return;
		for (int i = 0; i < 3; i++) {
			int next = 0;
			if (i == 0) next = cur - 1;
			else if (i == 1) next = cur + 1;
			else if (i == 2) next = cur * 2;
			if (next >= 0 && next < MAX && !visit[next]) {
				visit[next] = visit[cur] + 1;
				q.push(next);
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &K);
	bfs(N);
	printf("%d\n", visit[K]);
	return 0;
}