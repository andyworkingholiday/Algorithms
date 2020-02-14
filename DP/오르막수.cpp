#include <iostream>
#define MOD 10007
#define MAX 1001
using namespace std;

int n, sum;
int dp[1001][10];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 10; i++)
		dp[1][i] = 1;

	for (int i = 2; i <= n; i++) {
		dp[i][0] = 1;
		for (int j = 1; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] += (dp[i - 1][k] % MOD);
			}
		}
	}

	for (int i = 0; i < 10; i++)
		sum = (sum + dp[n][i]) % MOD;
	printf("%d\n", sum);
	return 0;
}