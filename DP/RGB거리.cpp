#include <iostream>
#include <algorithm>
#define MAX 1001
using namespace std;

int n, house[MAX][3], sum;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &house[i][j]);
		}
	}

	for (int i = 1; i <= n; i++) {
		house[i][0] += min(house[i - 1][1], house[i - 1][2]);
		house[i][1] += min(house[i - 1][0], house[i - 1][2]);
		house[i][2] += min(house[i - 1][0], house[i - 1][1]);
	}
	printf("%d\n", min(min(house[n][0], house[n][1]), house[n][2]));
	return 0;
}