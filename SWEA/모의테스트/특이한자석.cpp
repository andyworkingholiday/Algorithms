#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int K, map[4][9], magnet[4], ans;

void clock_right(int i) {
	for (int j = 7; j >=0; j--) {
		map[i][j + 1] = map[i][j];
	}
	map[i][0] = map[i][8];
}

void banclock_left(int i) {
	map[i][8] = map[i][0];
	for (int j = 0; j <= 7; j++) {
		map[i][j] = map[i][j + 1];
	}
}

void rotate(int i, int dir) {
	switch (dir) {
	case 1:
		clock_right(i);
		break;

	case -1:
		banclock_left(i);
		break;
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		ans = 0;
		scanf("%d", &K);
		memset(map, 0, sizeof(map));
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 8; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		while (K--) {
			memset(magnet, 0, sizeof(magnet));
			int a, b;
			scanf("%d %d", &a, &b);
			a--;
			magnet[a] = b;

			if (a == 0) {
				if (map[0][2] != map[1][6]) {
					magnet[1] = 0 - b;
					if (map[1][2] != map[2][6]) {
						magnet[2] = b;
						if (map[2][2] != map[3][6]) {
							magnet[3] = 0 - b;
						}
					}
				}
			}

			if (a == 1) {
				if (map[0][2] != map[1][6]) magnet[0] = 0 - b;
				if (map[1][2] != map[2][6]) {
					magnet[2] = 0 - b;
					if (map[2][2] != map[3][6]) {
						magnet[3] = b;
					}
				}
			}

			if (a == 2) {
				if (map[2][2] != map[3][6]) magnet[3] = 0 - b;
				if (map[1][2] != map[2][6]) {
					magnet[1] = 0 - b;
					if (map[1][6] != map[0][2]) {
						magnet[0] = b;
					}
				}
			}


			if (a == 3) {
				if (map[3][6] != map[2][2]) {
					magnet[2] = 0 - b;
					if (map[2][6] != map[1][2]) {
						magnet[1] = b;
						if (map[1][6] != map[0][2]) {
							magnet[0] = 0 - b;
						}
					}
				}
			}

			for (int i = 0; i < 4; i++) {
				if (magnet[i] == 1 || magnet[i] == -1)
					rotate(i, magnet[i]);
			}



		}

		for (int i = 0; i < 4; i++) {
			if (map[i][0] == 1) {
				ans += pow(2, i);
			}
		}

		printf("#%d %d\n", t, ans);
	}
	return 0;
}