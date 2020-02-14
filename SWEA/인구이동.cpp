#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#define MAX 50
using namespace std;

struct yx {
	int row, col;
};

int n, l, r;
int people, num;
int map[MAX][MAX];
bool check[MAX][MAX];
vector<yx> v;
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	for (int dir = 0; dir < 4; dir++) {
		int ny = y + dy[dir], nx = x + dx[dir];
		int diff = abs(map[y][x] - map[ny][nx]);
		if (ny<0 || nx<0 || ny>n - 1 || nx > n - 1) continue;
		if (diff >= l && diff <= r && !check[ny][nx]) {
			check[ny][nx] = true;
			people += map[ny][nx];
			num++;
			v.push_back({ ny,nx });
			dfs(ny, nx);
		}
	}
}


int main() {
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int ret = 0;
	bool flag = true;
	while (flag) {
		flag = false;
		memset(check, false, sizeof(check));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j]) {
					check[i][j] = true;
					people = map[i][j];
					num = 1;
					v.clear();
					v.push_back({ i,j });
					dfs(i, j);
					if (num >= 2) {
						flag = true;
						for (int i = 0; i < num; i++) {
							map[v[i].row][v[i].col] = people / num;
						}
					}
				}
			}
		}
		if(flag) ret++;
		else break;
	}
	printf("%d\n", ret);
}