#include <iostream>
#define MAX 21
using namespace std;

int N, S, numbers[MAX], cnt, cS;

void dfs(int index) {
	if (index == N) return;
	if (cS + numbers[index] == S) cnt++;
	dfs(index + 1);
	cS += numbers[index];
	dfs(index + 1);
	cS -= numbers[index];
}

int main() {
	scanf("%d %d", &N, &S);
	for (int i = 0; i < N; i++) 
		scanf("%d", &numbers[i]);
	dfs(0);
	printf("%d\n", cnt);
}