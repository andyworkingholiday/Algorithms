#include <iostream>
#include <queue>
#define MAX 100
using namespace std;

struct shark {
	int s, d, z;
};

struct yx {
	int y, x;
};


int r, c, m;
shark map[MAX][MAX];
const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,1,-1 };

int main() {
	scanf("%d %d %d", &r, &c, &m);
	for (int i = 0; i < m; i++) {
		int y, x, vel, direc, size;
		scanf("%d %d %d %d %d", &y, &x, &vel, &direc, &size);
		map[y - 1][x - 1] = { vel,direc - 1,size };
	}

	
	int result = 0;
	for (int index = 0; index < c; index++) {
		for (int i = 0; i < r; i++) {
			if (map[i][index].z > 0) {
				result += map[i][index].z;
				map[i][index] = { 0,0,0 };
				break;
			}
		}

		
		queue<pair<shark, yx>> q;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (map[i][j].z > 0) {
					q.push({ map[i][j], {i,j} });
					map[i][j] = { 0,0,0 };
				}
			}
		}

		while (!q.empty()) {
			int y = q.front().second.y;
			int x = q.front().second.x;
			int size = q.front().first.z;
			int dir = q.front().first.d;
			int speed = q.front().first.s;
			q.pop();
			for (int s = 0; s < speed; s++) {
				if (dir == 0 || dir == 1) {
					int ny = y + dy[dir];
					if (ny<0 || ny >r - 1)
						dir = 1 - dir;
					y += dy[dir];
				}

				else {
					int nx = x + dx[dir];
					if (nx<0 || nx>c - 1)
						dir = 5 - dir;
					x += dx[dir];
				}
			}


			if (map[y][x].z > 0) {
				if (map[y][x].z < size) {
					map[y][x] = { speed,dir,size };
				}
			}

			else
				map[y][x] = { speed,dir,size };


		}
	}
	printf("%d\n", result);
	return 0;
}