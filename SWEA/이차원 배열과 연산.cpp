#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#define MAX 100
using namespace std;

struct number {
	int n, count;
};

bool operator<(number a, number b) {
	if (a.count > b.count) {
		return true;
	}

	else if (a.count == b.count) {
		return (a.n > b.n);
	}
	return false;
}


int map[MAX][MAX];
int numbers[MAX + 1];
int r, c, k;
int nextr = 3, nextc = 3;

int main() {
	scanf("%d %d %d", &r, &c, &k);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	int time = 0;

	while (1) {
		int row_size = nextr;
		int col_size = nextc;
		priority_queue<number> q;
		if (map[r - 1][c - 1] == k || time > 100) break;
		if (row_size >= col_size) {
			for (int i = 0; i < row_size; i++) {
				memset(numbers, 0, sizeof(numbers));
				int x = 0;
				for (int j = 0; j < col_size; j++) {
					if (map[i][j]) {
						x = max(x, map[i][j]);
						numbers[map[i][j]]++;
					}
					map[i][j] = 0;
				}

				for (int j = 1; j <= x; j++) {
					if (numbers[j]) q.push({ j,numbers[j] });
				}

				int idx = 0;
				while (!q.empty()) {
					number x = q.top();
					q.pop();
					map[i][idx] = x.n;
					map[i][idx + 1] = x.count;
					idx += 2;
				}
				nextc = max(idx, nextc);
			}			
		}

		else {
			for (int j = 0; j < col_size; j++) {
				memset(numbers, 0, sizeof(numbers));
				int x = 0;
				for (int i = 0; i < row_size; i++) {
					if (map[i][j]) {
						x = max(x, map[i][j]);
						numbers[map[i][j]]++;
					}
					map[i][j] = 0;
				}

				for (int i = 1; i <= x; i++) {
					if (numbers[i]) q.push({ i,numbers[i] });
				}

				int idx = 0;
				while (!q.empty()) {
					number x = q.top();
					q.pop();
					map[idx][j] = x.n;
					map[idx+1][j] = x.count;
					idx += 2;
				}
				nextr = max(idx, nextr);
			}
		}
		time++;
		
	}

	if (time <= 100) printf("%d\n", time);
	else printf("-1\n");
	return 0;
}
