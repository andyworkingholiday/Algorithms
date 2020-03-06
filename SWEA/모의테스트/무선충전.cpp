#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct battery {
	int y, x, d, p;
};

int M, A;
battery bc[8];
const int dy[] = { 0,-1,0,1,0 };
const int dx[] = { 0,0,1,0,-1 };
int walka[101], walkb[101];
int sum;

int dist(int x, int y, int xx, int yy) {
	return (abs(x - xx) + abs(y - yy));
}

int calc(int ay, int ax, int by, int bx) {
	vector<int> a_bat;
	vector<int> b_bat;
	int a_max = 0;
	int b_max = 0;

	for (int i = 0; i < A; i++) {
		int bty = bc[i].y;
		int btx = bc[i].x;

		if (dist(ay, ax, bty, btx) <= bc[i].d) {
			a_bat.push_back(i);
			a_max = max(bc[i].p, a_max);
		}

		if (dist(by, bx, bty, btx) <= bc[i].d) {
			b_bat.push_back(i);
			b_max = max(bc[i].p, b_max);
		}
	}

	if (a_bat.size() == 0) {
		if (b_bat.size() == 0) return 0;
		else return b_max;
	}

	if (b_bat.size() == 0) {
		if (a_bat.size() == 0) return 0;
		else return a_max;
	}

	int max_energy = 0;

	for (int i = 0; i < a_bat.size(); i++) {
		for (int j = 0; j < b_bat.size(); j++) {
			int pa = bc[a_bat[i]].p;
			int pb = bc[b_bat[j]].p;
			if (a_bat[i] == b_bat[j]) pa /= 2, pb /= 2;
			max_energy = max(max_energy, pa + pb);
		}
	}
	return max_energy;
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		sum = 0;
		scanf("%d %d", &M, &A);
		for (int i = 1; i <= M; i++) {
			scanf("%d", walka + i);
		}
		for (int i = 1; i <= M; i++) {
			scanf("%d", walkb + i);
		}

		for (int i = 0; i < A; i++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			bc[i] = { b - 1,a - 1,c,d };
		}

		int fay = 0, fax = 0;
		int fby = 9, fbx = 9;

		for (int i = 0; i <= M; i++) {
			fay += dy[walka[i]], fax += dx[walka[i]];
			fby += dy[walkb[i]], fbx += dx[walkb[i]];
			sum += calc(fay, fax, fby, fbx);
		}
		printf("#%d %d\n", t, sum);
	}
	return 0;
}