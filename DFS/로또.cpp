#include <iostream>
#include <cstring>
using namespace std;

int K, arr[14], lotto[6];

void dfs(int index1, int index2) {
	if (index2 == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", lotto[i]);
		printf("\n");
		return;
	}

	for (int i = index1; i < K; i++) {
		lotto[index2] = arr[i];
		dfs(i + 1, index2 + 1);
	}

}

int main() {
	while (1) {
		memset(arr, 0, sizeof(arr));
		memset(lotto, 0, sizeof(lotto));
		scanf("%d", &K);
		if (K == 0) break;
		for (int i = 0; i < K; i++)
			scanf("%d", &arr[i]);
		dfs(0, 0);
		printf("\n");
	}
	return 0;
}