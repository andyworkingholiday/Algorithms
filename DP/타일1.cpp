#include <iostream>
#define MAX 1001
using namespace std;

int n;
long long tile[MAX];

int main() {
	scanf("%d", &n);
	tile[1] = 1, tile[2] = 2;
	for (int i = 3; i <= n; i++) {
		tile[i] = tile[i - 1] + tile[i - 2];
		tile[i] %= 10007;
	}

	printf("%lld\n", tile[n]);
	return 0;
}