#include <iostream>
#include <algorithm>
using namespace std;

int N = 0, ans = 0x7fffffff;
int map[20][20];
int team1[10], team2[10];
int people[20];

void calculate() {
	int index1 = 0, index2 = 0;
	for (int i = 0; i < N; i++) {
		if (people[i]) team1[index1++] = i;
		else team2[index2++] = i;
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < N / 2 -1; i++) {
		for (int j = i + 1; j < N / 2; j++) {
			sum1 += (map[team1[i]][team1[j]] + map[team1[j]][team1[i]]);
			sum2 += (map[team2[i]][team2[j]] + map[team2[j]][team2[i]]);
		}
	}
	ans = min(ans, abs(sum1 - sum2));
}

void dfs(int point, int cnt) {
	if (cnt == N / 2) {
		calculate();
		return;
	}

	for (int i = point; i < N; i++) {
		people[i] = 1;
		dfs(i + 1, cnt + 1);
		people[i] = 0;
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	dfs(0, 0);
	printf("%d\n", ans);
	return 0;
}