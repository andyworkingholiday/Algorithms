#include <iostream>
#include <algorithm>
#define MAX 501
using namespace std;

int n, arr[MAX][MAX], dp[MAX][MAX];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	dp[1][1] = arr[1][1];
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j == 1) dp[i][j] = dp[i - 1][j] + arr[i][j];
			if (j == n) dp[i][j] = dp[i - 1][j - 1] + arr[i][j];
			else dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + arr[i][j];
		}
	}
	int answer = dp[n][1];
	for (int i = 2; i <= n; i++)
		answer = max(answer, dp[n][i]);
	printf("%d\n", answer);
	return 0;
}