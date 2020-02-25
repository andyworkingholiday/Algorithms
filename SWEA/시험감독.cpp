#include <iostream>
#define MAX 1000000
using namespace std;

int testroom[MAX];
int n, b, c;
long long ret;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", testroom + i);
	}
	scanf("%d %d", &b, &c);


	for (int i = 0; i < n; i++) {
		if (b >= testroom[i]) ret++;
		else {
			testroom[i] -= b;
			ret++;
			if (testroom[i] % c != 0) {
				ret += ((testroom[i] / c) + 1);
			}

			else ret += testroom[i] / c;
		}
	}
	printf("%lld\n", ret);
	return 0;
}