#include <iostream>
using namespace std;

int N, M, H, ans;
int map[31][10];
bool success = false;
bool flag = false;

void sadari() {
	success = true;
	for (int index = 0; index < N; index++) {
		int i = 0, j = index;
		while (i != H) {

			if (map[i][j] == 1 && map[i][j+1]==2) {
				j++;
				i++;
			}

			else if (map[i][j] == 2 && map[i][j-1]==1) {
				j--;
				i++;
			}

			else {
				i++;
			}
		}

		if (j != index) {
			success = false;
			break;
		}
	}
}

void dfs(int posy, int posx, int cnt, int maxs) {
	if (flag) return;
	if (cnt == maxs) {
		sadari();
		if (success) {
			ans = maxs;
			flag = true;
		}
					
		return;
	}

	for (int i = posy; i < H; i++) {
		for (int j = posx; j < N-1; j++) {
			if (map[i][j] == 0 && map[i][j+1]==0) {
				map[i][j] = 1, map[i][j + 1] = 2;
				dfs(i, j, cnt + 1, maxs);
				map[i][j] = 0, map[i][j + 1] = 0;
			}
		}

		posx = 0;
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &H);
	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		map[a - 1][b - 1] = 1, map[a - 1][b] = 2;
	}


	sadari();

	if (success) {
		printf("0\n");
		return 0;
	}

	else {
		for (int i = 1; i <=3; i++) {
			dfs(0, 0, 0, i);
			if (flag) {
				printf("%d\n", ans);
				return 0;
			}
		}
	}

	printf("-1\n");
	return 0;
}