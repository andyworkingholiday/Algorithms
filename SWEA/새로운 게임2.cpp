#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct yxd{
	int y, x, d;
};

int N, K;
int turn = 1;
vector<int> v[12][12];
int map[12][12];
bool flag = false;
const int dy[] = { 0,0,-1,1 };
const int dx[] = { 1,-1,0,0 };
yxd horse[11];

void move() {
	while (1) {
		if (turn > 10) {
			turn = -1;
			break;
		}

		for (int idx = 1; idx <= K; idx++) {
			int cy = horse[idx].y;
			int cx = horse[idx].x;
			int cd = horse[idx].d;
			int ny = cy + dy[cd];
			int nx = cx + dx[cd];

			if (ny <0 || ny>N - 1 || nx<0 || nx>N - 1 || map[ny][nx] == 2) {
				if (cd % 2 == 0) cd += 1;
				else cd -= 1;
				ny = cy + dy[cd];
				nx = cx + dx[cd];
				horse[idx].d = cd;
				if (ny <0 || ny>N - 1 || nx<0 || nx>N - 1 || map[ny][nx] == 2) {
					ny = cy;
					nx = cx;
					continue;
				}
			}

			if (map[ny][nx] == 0) {
				stack<pair<int, int>> s;
				while (v[cy][cx].back()!= idx) {
					int num = v[cy][cx].back();
					int dir = horse[num].d;
					v[cy][cx].pop_back();
					s.push({ num,dir });
				}
				int last = v[cy][cx].back();
				s.push({ last, horse[last].d });
				v[cy][cx].pop_back();

				while (!s.empty()) {
					int num = s.top().first;
					int dir = s.top().second;
					s.pop();
					v[ny][nx].push_back(num);
					horse[num] = { ny,nx, dir };
				}
			}

			else if (map[ny][nx] == 1) {
				queue<pair<int, int>> q;
				while (v[cy][cx].back()!= idx) {
					int num = v[cy][cx].back();
					int dir = horse[num].d;
					v[cy][cx].pop_back();
					q.push({ num,dir });
				}

				int last = v[cy][cx].back();
				q.push({ last, horse[last].d });
				v[cy][cx].pop_back();

				while (!q.empty()) {
					int num = q.front().first;
					int dir = q.front().second;
					q.pop();
					v[ny][nx].push_back(num);
					horse[num] = { ny,nx,dir };
				}

			}

			if (v[ny][nx].size() >= 4) {
				return;
			}
		}
		turn++;	
	}
	
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	for (int i = 1; i<= K; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		horse[i] = { a - 1,b - 1,c - 1 };
		v[a - 1][b - 1].push_back(i);
	}

	int time = 0;
	move();
	printf("%d\n", turn);
	return 0;
}