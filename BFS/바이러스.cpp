#include <iostream>
#include <queue>
using namespace std;

int com[101][101];
int n, iter, answer;
queue<int> q;
bool check[101];

void bfs(int start) {
	q.push(start);
	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (com[now][i] == 1 && !check[i]) {
				check[i] = true;
				q.push(i);
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &iter);
	while (iter--) {
		int a = 0, b = 0;
		scanf("%d %d", &a, &b);
		com[a][b] = 1, com[b][a] = 1;
	}
	bfs(1);
	for (int i = 2; i <= n; i++)
		if (check[i]) answer++;
	printf("%d\n", answer);
	return 0;
}