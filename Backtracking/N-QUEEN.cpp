#include <iostream>
#define MAX 16
using namespace std;


int N, answer;
int queen[MAX];

bool is_queen(int n) {
	for (int i = 0; i < n; i++) {
		if (queen[i] == queen[n]) return false;
		if (n - i == abs(queen[n] - queen[i])) return false;
	}
	return true;
}

void dfs(int n) {
	if (n == N - 1) {
		answer++;
		return;
	}
	for (int i = 0; i < N; i++) {
		queen[n + 1] = i;
		if (is_queen(n + 1))
			dfs(n + 1);
	}
}



int main() {
	scanf("%d", &N);
	dfs(-1);
	printf("%d\n", answer);
}