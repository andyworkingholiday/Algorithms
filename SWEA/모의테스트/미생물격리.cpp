#include <iostream>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#define MAX 102
using namespace std;

struct node {
	int x, y, cnt, dir, ind;
	bool alive;

	node() { }
	node(int _x, int _y, int _cnt, int _dir, int _ind, bool _alive) {
		x = _x;
		y = _y;
		cnt = _cnt;
		dir = _dir;
		ind = _ind;
		alive = _alive;
	}
};

bool cmp(node &n1, node &n2) {
	return n1.cnt < n2.cnt;
}

int testcase;
int n, m, k, ans;
int row, col, cnt, dir;

vector<int> map[MAX][MAX];

int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

vector<node> colony;

int changeDir(int dir) {
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else return 3;
}

int main(int argc, const char * argv[]) {
	// cin,cout 속도향상
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> n >> m >> k;

		// 입력
		for (int i = 0; i < k; i++) {
			cin >> row >> col >> cnt >> dir;

			colony.push_back(node(row, col, cnt, dir, i, true));
			map[row][col].push_back(i);
		}

		// m 시간 만큼 이동!!
		for (int i = 0; i < m; i++) {

			// 미생물 삭제
			for (int j = 0; j < colony.size(); j++) {
				if (!colony[j].alive) continue;

				map[colony[j].x][colony[j].y].pop_back();
			}

			// 미생물 이동
			for (int j = 0; j < colony.size(); j++) {
				if (!colony[j].alive) continue;

				int nx = colony[j].x + dx[colony[j].dir];
				int ny = colony[j].y + dy[colony[j].dir];

				colony[j].x = nx;
				colony[j].y = ny;
				map[nx][ny].push_back(colony[j].ind);

				// 이동한 노드에 약품이 발라져있다면
				if (nx == 0 || ny == 0 || nx == n - 1 || ny == n - 1) {
					colony[j].cnt /= 2;
					colony[j].dir = changeDir(colony[j].dir);
				}
			}

			// 미생물 확인
			for (int j = 0; j < colony.size(); j++) {
				if (!colony[j].alive) continue;

				int x = colony[j].x;
				int y = colony[j].y;

				// 군집이 1개 일 경우
				if (map[x][y].size() == 1) {

					// 미생물이 모두 죽은 경우
					if (colony[j].cnt <= 0) {
						colony[j].alive = false;
					}
				}
				// 군집이 2개 이상 모인 경우
				else if (map[x][y].size() > 1) {
					// 최대 미생물을 가진 군집을 찾음
					node max_node = colony[map[x][y][0]];
					int sum = colony[map[x][y][0]].cnt;

					for (int l = 1; l < map[x][y].size(); l++) {
						sum += colony[map[x][y][l]].cnt;

						node node = colony[map[x][y][l]];
						if (max_node.cnt < node.cnt) {
							max_node = node;
						}
					}

					// 최대 군집을 제외한 나머지 군집 죽음
					for (int l = 0; l < map[x][y].size(); l++) {
						if (colony[map[x][y][l]].ind == max_node.ind) {
							colony[map[x][y][l]].cnt = sum;
						}
						else {
							colony[map[x][y][l]].alive = false;
						}
					}

					map[x][y].clear();
					map[x][y].push_back(max_node.ind);
				}
			}
		}

		ans = 0;

		for (int i = 0; i < colony.size(); i++) {
			if (colony[i].alive) ans += colony[i].cnt;
		}

		// 초기화
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				map[i][j].clear();
			}
		}
		colony.clear();

		cout << "#" << t << " " << ans << "\n";
	}

	return 0;
}