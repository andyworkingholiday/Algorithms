#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M, house, K, cnt, ans;
int map[20][20];

void draw(int y, int x, int k) {
	cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (abs(i - y) + abs(j - x) < k) {
				if (map[i][j] == 1) {
					cnt++;
				}
			}
		}
	}
}

int main() {
	int test;
	scanf("%d", &test);
	for (int t = 1; t <= test; t++) {
		ans = 0, cnt = 0, house = 0;
		memset(map, 0, sizeof(map));
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				if (map[i][j] == 1) house++;
			}
		}

		K = 46;

		for (int i = 1; i <= K; i++) {
			if (i * i + (i - 1) * (i - 1) >= M * house) {
				K = i;
				break;
			}
		}

		for (int k = K; k >= 1; k--) {
			int money = k * k + (k - 1) * (k - 1);

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					draw(i, j, k);
					if (money <= cnt * M) {
						ans = max(ans, cnt);
					}
				}
			}

		}

		printf("#%d %d\n", t, ans);
	}

	return 0;
}