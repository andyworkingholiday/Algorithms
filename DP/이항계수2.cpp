#include <iostream>
#define MOD 10007
#define MAX 1001
using namespace std;

int n, k;
int dp[MAX][MAX];

int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)
		dp[i][0] = 1, dp[i][i] = 1;
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < n; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD;
		}
	}

	printf("%d\n", dp[n][k]);
	return 0;
}