#include <iostream>
#include <vector>
using namespace std;

int N;
int map[12][12];
int cores, length;
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
vector<pair<int, int>> v;


void counting(int idx, int core_count, int wire_count, int n) {
	if (cores > v.size() - n + core_count) return;
	if (n == v.size()) {
		if (cores < core_count) {
			cores = core_count;
			length = wire_count;
		}

		else if (cores == core_count) {
			if (length > wire_count) length = wire_count;
		}
		return;
	}

	int temp[12][12] = { 0, };

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp[i][j] = map[i][j];
		}
	}

	for (int dir = 0; dir < 4; dir++) {
		int ny = 0, nx = 0, cnt = 0;
		int y = v[idx].first;
		int x = v[idx].second;
		bool flag = true;

		while (1) {
			ny = y + dy[dir];
			nx = x + dx[dir];
			if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1) break;
			if (map[ny][nx] == 1 || map[ny][nx] == 2) {
				flag = false;
				break;
			}

			cnt++;
			map[ny][nx] = 2;
			y = ny;
			x = nx;
		}

		if (flag) {
			counting(idx + 1, core_count + 1, wire_count + cnt, n + 1);
		}

		if (cnt != 0) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = temp[i][j];
				}
			}
		}
	}

	counting(idx + 1, core_count, wire_count, n + 1);
}

int main() {
	int test;
	scanf("%d", &test);
	for(int x=1; x<=test; x++) {
		memset(map, false, sizeof(map));
		cores = 0, length = 0;
		v.clear();
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (i == 0 || j == 0 || i == N - 1 || j == N - 1) continue;
				if (map[i][j] == 1)
					v.push_back({ i, j });
			}
		}

		counting(0, 0, 0, 0);
		printf("#%d %d\n", x, length);
	}
	return 0;
}