#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int w[101], v[101];
int dp[101][100001];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d", w + i, v + i);
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i] >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
			}
		}
	}
	printf("%d\n", dp[n][k]);
	return 0;
}