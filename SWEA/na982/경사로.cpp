#include <iostream>
using namespace std;

int N, L, ans, cnt;
int map[200][100];

int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			map[N + j][i] = map[i][j];
		}
	}

	int i, j;
	for (i = 0; i < 2 * N; i++) {
		cnt = 1;
		for (j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) cnt++;
			else if (map[i][j] + 1 == map[i][j + 1] && cnt >= L) cnt = 1;
			else if (map[i][j] - 1 == map[i][j + 1] && cnt >= 0) cnt = 1 - L;
			else break;
		}
		if (j == N - 1 && cnt >= 0) ans++;
	}
	printf("%d\n", ans);
	return 0;
}