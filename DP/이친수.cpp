#include <iostream>
#define MAX 91
using namespace std;

long long dp[2][MAX];
int n;

int main() {
	scanf("%d", &n);
	dp[0][0] = 0, dp[1][0] = 1;
	dp[0][1] = 1, dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[0][i] = dp[0][i - 1] + dp[1][i - 1];
		dp[1][i] = dp[0][i - 1];
	}
	printf("%lld\n", dp[0][n - 1] + dp[1][n - 1]);
	return 0;
}