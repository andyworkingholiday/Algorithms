#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, start;
vector<int> visit;
vector<int> edge[1001];

void dfs(int start) {
	if (visit[start - 1])
		return;
	visit[start - 1] = true;
	printf("%d ", start);
	for (int i = 0; i < edge[start].size(); i++) {
		int x = edge[start][i];
		dfs(x);
	}

}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visit[start - 1] = true;
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		printf("%d ", x);
		for (int i = 0; i < edge[x].size(); i++) {
			int y = edge[x][i];
			if (!visit[y - 1]) {
				q.push(y);
				visit[y - 1] = true;
			}
		}
	}
}


int main() {
	scanf("%d %d %d", &N, &M, &start);
	int node1, node2;
	visit = vector<int>(N, 0);
	for (int i = 0; i < M; i++) {
		
		scanf("%d %d", &node1, &node2);
		edge[node1].push_back(node2);
		edge[node2].push_back(node1);
		
	}

	for (int i = 1; i <= N; i++) {
		sort(edge[i].begin(), edge[i].end());		
	}

	dfs(start);
	printf("\n");
	visit = vector<int>(N, 0);
	bfs(start);
	printf("\n");
}