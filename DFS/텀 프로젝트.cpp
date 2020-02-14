#include <iostream>
#include <cstring>
using namespace std;

int N, answer;
int nodes[100001];
bool check[100001];
bool finish[100001];

void dfs(int n) {
	check[n] = true;
	int next = nodes[n];
	if (!check[next])
		dfs(next);
	else if (!finish[next]) {
		for (int i = next; i != n; i = nodes[i])
			answer++;
		answer++;
	}
	finish[n] = true;
}


int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(check, 0, sizeof(check));
		memset(finish, 0, sizeof(finish));
		for (int i = 1; i <= N; i++) {
			scanf("%d", &nodes[i]);
		}
		answer = 0;
		for (int i = 1; i <= N; i++) {
			if (!finish[i])
				dfs(i);
		}
		cout << N - answer << endl;
	}
	return 0;
}