#include <iostream>
using namespace std;

bool map[100][100];
int t;

int main() {
	int ret = 0;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d %d", &a, &b);
		for (int i = 100 - b - 9; i <= 100 - b; i++) {
			for (int j = a; j <= a + 9; j++) {
				if (!map[i][j]) {
					map[i][j] = true;
					ret++;
				}
			}
		}
	}

	printf("%d\n", ret);
	return 0;
}