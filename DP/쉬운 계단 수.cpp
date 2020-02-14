#include <iostream>
#define mod 1000000000
using namespace std;

int n;
long long sum;
int dp[10][101];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= 9; i++)
		dp[i][1] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j == 0) dp[j][i] = dp[j + 1][i - 1] % mod;
			else if (j == 9) dp[j][i] = dp[j - 1][i - 1] % mod;
			else dp[j][i] = (dp[j - 1][i - 1] + dp[j + 1][i - 1]) % mod;
		}
	}
	for (int i = 0; i <= 9; i++) sum = (sum + dp[i][n]) % mod;
	printf("%lld\n", sum);
	return 0;
}