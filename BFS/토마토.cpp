#include <iostream>
#include <queue>
#define MAX 1001	
using namespace std;

int M, N, answer;
int tomato[MAX][MAX];
int check[MAX][MAX];
const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };
queue<pair<int, int>> q;

void bfs() {
	while (!q.empty()) {
		int tsize = q.size();
		while (tsize--) {
			int ty = q.front().first;
			int tx = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = ty + dy[i], nx = tx + dx[i];
				if (ny <0 || ny >N - 1 || nx<0 || nx>M - 1) continue;
				if (tomato[ny][nx] == 0 && !check[ny][nx]) {
					tomato[ny][nx] = 1;
					check[ny][nx] = check[ty][tx] + 1;
					q.push(pair<int, int>(ny, nx));
				}
			}
			
		}
	}
}


int main() {
	scanf("%d %d", &M, &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &tomato[i][j]);
			if (tomato[i][j] == 1) {
				q.push(pair<int, int>(i, j));
				check[i][j] = 1;
			}
		}
	}
	bfs();


	int flag = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			answer = max(answer, check[i][j] - 1);
			if(tomato[i][j] == 0 && check[i][j] == 0) {
				answer = -1, flag = 1;
				break;
			}				
		}
		if (flag) break;
		
	}
	printf("%d\n", answer);
}