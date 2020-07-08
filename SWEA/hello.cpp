#include <iostream>
#include <vector>
using namespace std;

struct shark {
	int y;
	int x;
	int life;
	int cd;
	int fdir[4][4];
};

struct blood {
	int no;
	int time;
};

int N, M, K;
blood map[20][20];
shark sharks[401];

const int dy[] = { -1,1,0,0 };
const int dx[] = { 0,0,-1,1 };

void move() {
	for (int idx = 1; idx <= M; idx++) {
		if (!sharks[idx].life) continue;
		int cy = sharks[idx].y; int cx = sharks[idx].x; int cdir = sharks[idx].cd;
		map[cy][cx].time--;
		if (map[cy][cx].time == 0)
			map[cy][cx] = { 0,0 };
		
		bool isEmpty = false;
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[sharks[idx].fdir[cdir][dir]];
			int nx = cx + dx[sharks[idx].fdir[cdir][dir]];
			if (ny<0 || ny>N || nx<0 || nx>N) continue;
			if (map[ny][nx].no == 0) {
				map[ny][nx] = { idx, K };
				sharks[idx].cd = sharks[idx].fdir[cdir][dir];
				sharks[idx].y = ny; sharks[idx].x = nx;
				isEmpty = true;
				break;
			}

			else if (map[ny][nx].no!=idx && map[ny][nx].no>=1) {
				if (map[ny][nx].time == K) {
					sharks[idx].life = false;
					isEmpty = true;
					break;
				}
			}
		}

		if (!isEmpty) {
			for (int dir = 0; dir < 4; dir++) {
				int ny = cy + dy[sharks[idx].fdir[cdir][dir]];
				int nx = cx + dx[sharks[idx].fdir[cdir][dir]];
				if (ny<0 || ny>N || nx<0 || nx>N) continue;
				if (map[ny][nx].no == idx) {
					map[ny][nx] = { idx,K };
					sharks[idx].cd = sharks[idx].fdir[cdir][dir];
					sharks[idx].y = ny; sharks[idx].x = nx;
					isEmpty = true;
					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j].no >= 1 && map[i][j].time ==K-2) {
				map[i][j].time--;
				if (map[i][j].time == 0) map[i][j].no = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int a; 
			scanf("%d", &a);
			if (a != 0) {
				map[i][j] = { a,K };
				sharks[a].y = i; sharks[a].x = j; sharks[a].life = true;
			}

			else map[i][j] = { 0,0 };
		}
	}

	for (int i = 1; i <= M; i++) {
		int direction;
		scanf("%d", &direction);
		direction--;
		sharks[i].cd = direction;
	}

	for (int x = 1; x <= M; x++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int a;
				scanf("%d", &a);
				a--;
				sharks[x].fdir[i][j] = a;
			}
		}
	}

	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j].no << " ";
		}
		cout << endl;
	}

	cout << endl;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << map[i][j].time << " ";
		}
		cout << endl;
	}

	int k = 1;
	while (k <= 5) {

		cout << endl << "--------" << k << "--------" << endl;
		move();

		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j].no << " ";
			}
			cout << endl;
		}

		cout << endl;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cout << map[i][j].time << " ";
			}
			cout << endl;
		}

		k++;
	}
}