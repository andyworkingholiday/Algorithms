#include <iostream>
#include <queue>
#include <cstring>
#define MAX 101
using namespace std;


int N, M, mins = 99999;
int bacon[MAX][MAX];
int check[MAX];

int bfs(int start) {
	memset(check, 0, sizeof(check));
	int answer = 0;
	queue<int> q;
	q.push(start);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= N; i++) {
			if (bacon[cur][i] == 1 && !check[i]) {
				q.push(i);
				check[i] = check[cur] + 1;
			}
		}
	}
	for (int i = 1; i <= N; i++) 
		if (i != start) answer += check[i];

	return answer;
}

int main() {
	scanf("%d %d", &N, &M);
	while (M--) {
		int a, b;
		scanf("%d %d", &a, &b);
		bacon[a][b] = 1, bacon[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		mins = min(mins, bfs(i));
	}
	for (int i = 1; i <= N; i++) {
		if (mins == bfs(i)) {
			printf("%d\n", i);
			break;
		}	
	}
	return 0;
}