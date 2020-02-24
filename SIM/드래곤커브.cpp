#include <iostream>
#include <cmath>
#include <cstring>
#define MAX 101
using namespace std;

int n;
const int dy[] = { 0,-1,0,1 };
const int dx[] = { 1,0,-1,0 };
int map[MAX+1][MAX+1];
int direction[1024];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		memset(direction, 0, sizeof(direction));
		int x, y, d, g;
		scanf("%d %d %d %d", &x, &y, &d, &g);

		map[y][x] = 1;
		direction[0] = d;

		for (int j = 1; j <= g; j++) {
			int e = pow(2, j) - 1;
			int s = pow(2, j - 1);
			for (int k = e; k >= s; k--) {
				direction[k] = (direction[e - k] + 1) % 4;
			}
		}

		for (int j = 0; j < pow(2, g); j++) {
			y = y + dy[direction[j]];
			x = x + dx[direction[j]];
			map[y][x] = 1;
		}
	}

	int ret = 0;


	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1])
				ret++;
		}
	}

	printf("%d\n", ret);
	return 0;
}