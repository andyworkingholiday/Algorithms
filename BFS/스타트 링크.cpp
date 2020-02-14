#include <iostream>
#include <queue>
using namespace std;
#define MAX 1000001

int F, S, G, U, D;
int check[MAX];

int bfs(int x, int* updown) {
	queue<int> q;
	q.push(x);
	check[x] = 1;
	while (!q.empty()) {
		int floor = q.front();
		q.pop();
		if (floor == G) return check[floor] - 1;
		for (int i = 0; i < 2; i++) {
			int next_floor;
			if (i == 0) next_floor = floor + updown[0];
			else next_floor = floor - updown[1];
			if (next_floor > F || next_floor < 1) continue;
			if (!check[next_floor]) {
				check[next_floor] = check[floor] + 1;
				q.push(next_floor);
			}
		}
		
	}
	return -1;

}

int main() {
	scanf("%d %d %d %d %d", &F, &S, &G, &U, &D);
	int up_and_down[2] = { U,D };
	int result = bfs(S, up_and_down);

	if (result == -1) printf("use the stairs");
	else printf("%d", result);
	return 0;
}