#include <iostream>
#include <cstring>
#include <algorithm>
#define MAX 100001

using namespace std;

int T, N;
int sticker[2][MAX];
int dp[2][MAX];

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &sticker[i][j]);
			}
		}

		dp[0][0] = sticker[0][0];
		dp[1][0] = sticker[1][0];
		dp[0][1] = sticker[0][1] + dp[1][0];
		dp[1][1] = sticker[1][1] + dp[0][0];
		for (int i = 2; i < N; i++) {
			dp[0][i] = sticker[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = sticker[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}

		printf("%d\n", max(dp[0][N - 1], dp[1][N - 1]));
	}
	return 0;
		
}