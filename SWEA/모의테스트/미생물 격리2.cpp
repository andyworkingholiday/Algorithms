#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct bacteria {
	int y, x, num, dir;
	bool life;
};

vector<bacteria> misang;
int N, M, K;
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };

bool cmp(int a, int b) {
	return (misang[a].num > misang[b].num);
}

int main() {
	int test;
	scanf("%d", &test);

	for (int iter = 1; iter <= test; iter++) {
		scanf("%d %d %d", &N, &M, &K);

		vector<int> v[100][100];
		misang.clear();

		for (int i = 0; i < K; i++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			misang.push_back({ a,b,c,d - 1, true });
		}

		while (M--) {
			queue<bacteria> q;
			for (int i = 0; i < misang.size(); i++) {
				if (misang[i].life) q.push(misang[i]);
			}

			misang.clear();
			while (!q.empty()) {
				misang.push_back(q.front());
				q.pop();
			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					v[i][j].clear();
				}
			}

			for (int i = 0; i < misang.size(); i++) {
				int y = misang[i].y;
				int x = misang[i].x;
				int dir = misang[i].dir;

				int ny = y + dy[dir];
				int nx = x + dx[dir];
				if (ny == 0 || nx == 0 || ny == N - 1 || nx == N - 1) {
					misang[i].num /= 2;
					if (dir % 2 == 0) misang[i].dir = dir + 1;
					else misang[i].dir = dir - 1;
				}

				if (misang[i].num) {
					v[ny][nx].push_back(i);
					misang[i].y = ny;
					misang[i].x = nx;
				}
				else misang[i].life = false;

			}

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (v[i][j].size() >= 2) {
						sort(v[i][j].begin(), v[i][j].end(), cmp);
						int first = v[i][j][0];
						while (v[i][j].size() > 1) {
							int idx = v[i][j].back();
							misang[idx].life = false;
							misang[first].num += misang[idx].num;
							v[i][j].pop_back();
						}
					}
				}
			}
		}

		int answer = 0;
		for (int i = 0; i < misang.size(); i++) {
			if (misang[i].life) answer += misang[i].num;
		}
		printf("#%d %d\n", iter, answer);

	}
	return 0;	
}