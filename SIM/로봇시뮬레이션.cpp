#include <iostream>
#include <vector>
using namespace std;

struct command {
	int a;
	char d;
	int b;
};

struct robot {
	int y, x, d, n;
};



const int dy[] = { 0,1,0,-1 };
const int dx[] = { 1,0,-1,0 };
command commands[100];

int A, B, N, M;
int map[100][100];
vector<robot> v;

int change(char c) {
	switch (c) {
	case 'E':
		return 0;
	case 'S':
		return 1;
	case 'W':
		return 2;
	case 'N':
		return 3;
	}
}

bool move(int a, char c) {
	robot r = v[a];
	switch (c) {
	case 'L':
		v[a].d = (v[a].d + 3) % 4;
		return 1;
		break;

	case 'R':
		v[a].d = (v[a].d + 1) % 4;
		return 1;
		break;

	case 'F':
		int cy = r.y;
		int cx = r.x;
		int ny = cy + dy[r.d];
		int nx = cx + dx[r.d];

		if (ny <0 || ny> B - 1 || nx<0 || nx>A - 1) {
			printf("Robot %d crashes into the wall\n", r.n);
			return false;
		}

		else if (map[ny][nx] != 0) {
			printf("Robot %d crashes into robot %d\n", r.n, map[ny][nx]);
			return false;
		}

		else {
			v[a].y = ny;
			v[a].x = nx;
			map[cy][cx] = 0;
			map[ny][nx] = r.n;
			return true;
		}
		break;
	}
}

int main() {
	bool flag = false;
	scanf("%d %d", &A, &B); //a=5 b=4
	scanf("%d %d", &N, &M);
	v.push_back({ 0,0,0 });
	for (int i = 1; i <= N; i++) {
		int a, b;
		char c;
		scanf("%d %d %c", &a, &b, &c);
		map[B - b][a - 1] = i;
		v.push_back({ B - b, a - 1, change(c), i});
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		char d;
		scanf("%d %c %d", &a, &d, &b);
		commands[i] = { a,d,b };
	}

	for (int i = 0; i < M; i++) {
		int a = commands[i].a;
		char d = commands[i].d;
		int b = commands[i].b;
		while (b--) {
			if (!move(a, d)) {
				flag = true;
				break;
			}
		}

		if (flag) break;
	}

	if (!flag) printf("OK\n");
	return 0;
}