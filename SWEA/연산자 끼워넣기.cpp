#include <iostream>
#include <algorithm>
#define MAX 987654321
#define MIN -987654321
using namespace std;

int N, sum;
int arr[11];
int calculate[4];
int maxs = MIN, mins = MAX;

void dfs(int cnt) {
	if (cnt == N - 1) {
		maxs = max(maxs, sum);
		mins = min(mins, sum);
		return;
	}

	if (calculate[0]) {
		sum += arr[cnt + 1];
		calculate[0]--;
		dfs(cnt + 1);
		calculate[0]++;
		sum -= arr[cnt + 1];
	}

	if (calculate[1]) {
		sum -= arr[cnt + 1];
		calculate[1]--;
		dfs(cnt + 1);
		calculate[1]++;
		sum += arr[cnt + 1];
	}
	
	if (calculate[2]) {
		sum *= arr[cnt + 1];
		calculate[2]--;
		dfs(cnt + 1);
		calculate[2]++;
		sum /= arr[cnt + 1];
	}

	if (calculate[3]) {
		int p = sum % arr[cnt + 1];
		sum /= arr[cnt + 1];
		calculate[3]--;
		dfs(cnt + 1);
		calculate[3]++;
		sum = sum * arr[cnt + 1] + p;
	}

}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", arr + i);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", calculate + i);
	}
	sum = arr[0];

	dfs(0);
	printf("%d\n%d\n", maxs, mins);
	return 0;
}