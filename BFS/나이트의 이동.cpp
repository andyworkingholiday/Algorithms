#include <iostream>
#include <cstring>
#include <queue>
#define MAX 301
using namespace std;

int T, I;
int chess[MAX][MAX];
int check[MAX][MAX];
int dx[] = { 2,1,-1,-2,2,1,-1,-2 }, dy[] = { -1,-2,-2,-1,1,2,2,1 };


void bfs(int y, int x) {
	check[y][x] = 1;
	queue<pair<int, int>> q;
	q.push(pair<int, int>(y, x));
	while (!q.empty()) {
		int curr_y = q.front().first;
		int curr_x = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int ny = curr_y + dy[i], nx = curr_x + dx[i];
			if (ny<0 || ny>I - 1 || nx<0 || nx>I - 1) continue;
			if (!check[ny][nx]) {
				check[ny][nx] = check[curr_y][curr_x] + 1;
				q.push(pair<int, int>(ny, nx));
			}
		}
	}
	
}


int main() {
	scanf("%d", &T);
	while (T--) {
		memset(chess, 0, sizeof(chess));
		memset(check, 0, sizeof(check));
		int start_y, start_x, final_y, final_x;
		scanf("%d", &I);
		scanf("%d %d", &start_y, &start_x);
		scanf("%d %d", &final_y, &final_x);
		bfs(start_y, start_x);
		printf("%d\n", check[final_y][final_x] - 1);
	}

	return 0;
}