#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;

int n, stairs[MAX], dp[MAX];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", stairs + i);

	dp[1] = stairs[1], dp[2] = stairs[2] + stairs[1];
	for (int i = 3; i <= n; i++) {
		dp[i] = max(dp[i - 3] + stairs[i - 1], dp[i - 2]) + stairs[i];
	}
	printf("%d\n", dp[n]);
	return 0;
}