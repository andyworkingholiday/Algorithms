#include <iostream>
#include <queue>
#define MAX 1001
using namespace std;  

struct xyz {
	int y, x, z;
};
//스트럭트를 이용해서 q에 넣고 뺄 수 있다.

int N, M;
int map[MAX][MAX];
int check[MAX][MAX][2];

const int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

int  bfs(int y, int x) {
	queue<xyz> q;
	q.push({ y,x,0 });
	check[y][x][0] = 1;
	while (!q.empty()) {
		int curry = q.front().y;
		int currx = q.front().x;
		int currz = q.front().z;
		q.pop();
		if (curry == N - 1 && currx == M - 1) return check[curry][currx][currz];
		for (int i = 0; i < 4; i++) {
			int ny = curry + dy[i];
			int nx = currx + dx[i];
			if (ny<0 || ny>N - 1 || nx<0 || nx> M - 1) continue;
			if (map[ny][nx] == 0 && !check[ny][nx][currz]) {
				check[ny][nx][currz] = check[curry][currx][currz] + 1;
				q.push({ ny,nx,currz });
			}
			if (map[ny][nx] == 1 && currz == 0 && !check[ny][nx][currz]) {
				check[ny][nx][1] = check[curry][currx][currz] + 1;
				q.push({ ny,nx,1 });
			}
		}
		
	}
	return -1;
}
 
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	printf("%d\n", bfs(0, 0));
	return 0;
}