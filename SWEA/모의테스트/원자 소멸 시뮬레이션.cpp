#include <iostream>
#include <vector>
#include <queue>
#define MAX 4001
#define HALF (MAX-1)/2
using namespace std;
struct atom {
	int y, x, dir, energy;
	bool life;
};

int N, ans;
int map[MAX][MAX];
vector<atom> v;

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

bool alldie() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].life) return false;
	}
	return true;
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		scanf("%d", &N);
		v.clear();
		ans = 0;
		for (int i = 0; i < N; i++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			a *= 2, b *= 2;
			v.push_back({ HALF - b, HALF + a, c, d, true });
			map[HALF - b][HALF + a] = 1;
		}

		while (1) {
			if (alldie()) break;
			for (int i = 0; i < v.size(); i++) {
				if (!v[i].life) continue;
				int y = v[i].y;
				int x = v[i].x;
				int dir = v[i].dir;
				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny <0 || ny> MAX - 1 || nx<0 || nx>MAX - 1) {
					v[i].life = false;
					map[y][x] = 0;
				}

				else {
					map[y][x] = 0;
					map[ny][nx] += 1;
					v[i].y = ny;
					v[i].x = nx;
				}
			}

			for (int i = 0; i < v.size(); i++) {
				if (!v[i].life) continue;
				int y = v[i].y;
				int x = v[i].x;
				if (map[y][x] > 1) {
					for (int j = 0; j < v.size(); j++) {
						if (i == j) continue;
						if (!v[j].life) continue;
						int yy = v[j].y;
						int xx = v[j].x;
						if (x == xx && y == yy) {
							ans += v[j].energy;
							v[j].life = false;
						}
					}
					ans += v[i].energy;
					v[i].life = false;
					map[y][x] = 0;
				}
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}