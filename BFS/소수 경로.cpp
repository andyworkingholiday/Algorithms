#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#define MAX 10000
using namespace std;

int check[MAX];

bool isprime(int n) {
	bool flag = true;
	int half = n / 2 + 1;
	for (int i = 2; i < half; i++) {
		if (n%i == 0) {
			flag = false;
			break;
		}
	}
	return flag;
}

void bfs(int start) {
	queue<int> q;
	q.push(start);
	check[start] = 0;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			string scur = to_string(cur);
			for (int j = 0; j < 10; j++) {
				scur[i] = j + '0';
				int next = stoi(scur);
				if (next >= 1000 && isprime(next) && check[next] == -1) {
					check[next] = check[cur] + 1;
					q.push(next);
				}
			}
		}
	}

}

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		memset(check, -1, sizeof(check));
		int a, b;
		scanf("%d %d", &a, &b);
		bfs(a);
		if (check[b] != -1) printf("%d\n", check[b]);
		else printf("Impossible\n");
	}
}