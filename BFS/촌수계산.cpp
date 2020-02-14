#include <iostream>
#include <queue>
using namespace std;
#define MAX 101

int n, p1, p2, m;
int result[MAX];
int family[MAX][MAX];
queue<int> q;

void bfs(int start) {

	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (family[now][i] == 1 && result[i] == 0) {
				result[i] = result[now] + 1;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &p1, &p2, &m);
	int a, b;
	while (m--) {
		scanf("%d %d", &a, &b);
		family[a][b] = 1, family[b][a] = 1;
	}
	bfs(p1);
	if (!result[p2])
		printf("%d", -1);
	else
		printf("%d", result[p2]);

	return 0;
}