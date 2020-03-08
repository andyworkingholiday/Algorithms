#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

int map[20][20];
int N, ans;

void up() {
	for (int j = 0; j < N; j++) {
		queue<int> q;
		for (int i = 0; i < N; i++) {
			if (map[i][j] != 0) q.push(map[i][j]);
			map[i][j] = 0;
		}
		int size = q.size();
		int idx = 0;
		while (!q.empty()) {
			map[idx][j] = q.front();
			q.pop();
			idx++;
		}

		if (size > 1) {
			for (int i = 1; i < size; i++) {
				if (map[i - 1][j] == map[i][j]) {
					map[i - 1][j] *= 2;
					map[i][j] = 0;
				}
			}
			for (int i = 0; i < size; i++) {
				if (map[i][j] != 0) q.push(map[i][j]);
				map[i][j] = 0;
			}
			idx = 0;
			while (!q.empty()) {
				map[idx][j] = q.front();
				q.pop();
				idx++;
			}
		}
	}
}

void down() {
	for (int j = 0; j < N; j++) {
		stack<int> s;
		for (int i = 0; i < N; i++) {
			if (map[i][j] != 0) s.push(map[i][j]);
			map[i][j] = 0;
		}
		int size = s.size();
		int idx = N - 1;
		while (!s.empty()) {
			map[idx][j] = s.top();
			s.pop();
			idx--;
		}

		if (size > 1) {
			for (int i = N - 2; i >= N - size; i--) {
				if (map[i + 1][j] == map[i][j]) {
					map[i + 1][j] *= 2;
					map[i][j] = 0;
				}
			}

			for (int i = N-size; i < N; i++) {
				if (map[i][j] != 0) s.push(map[i][j]);
				map[i][j] = 0;
			}

			idx = N - 1;
			while (!s.empty()) {
				map[idx][j] = s.top();
				s.pop();
				idx--;
			}
		}

	}
}

void right() {
	for (int i = 0; i < N; i++) {
		stack<int> s;
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) s.push(map[i][j]);
			map[i][j] = 0;
		}
		int size = s.size();
		int idx = N - 1;
		while (!s.empty()) {
			map[i][idx] = s.top();
			s.pop();
			idx--;
		}

		if (size > 1) {
			for (int j = N - 2; j >= N - size; j--) {
				if (map[i][j+1] == map[i][j]) {
					map[i][j + 1] *= 2;
					map[i][j] = 0;
				}
			}

			for (int j = N-size; j < N; j++) {
				if (map[i][j] != 0) s.push(map[i][j]);
				map[i][j] = 0;
			}

			idx = N - 1;
			while (!s.empty()) {
				map[i][idx] = s.top();
				s.pop();
				idx--;
			}
		}
	}
}

void left() {
	for (int i = 0; i < N; i++) {
		queue<int> q;
		for (int j = 0; j < N; j++) {
			if (map[i][j] != 0) q.push(map[i][j]);
			map[i][j] = 0;
		}
		int idx = 0;
		int size = q.size();
		while (!q.empty()) {
			map[i][idx] = q.front();
			q.pop();
			idx++;
		}

		if (size > 1) {
			for (int j = 1; j < size; j++) {
				if (map[i][j-1] == map[i][j]) {
					map[i][j - 1] *= 2;
					map[i][j] = 0;
				}
			}

			for (int j = 0; j < size; j++) {
				if (map[i][j] != 0) q.push(map[i][j]);
				map[i][j] = 0;
			}
			idx = 0;
			while (!q.empty()) {
				map[i][idx] = q.front();
				q.pop();
				idx++;
			}
		}
	}
}

void copys(int a[20][20], int b[20][20]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void bt(int pos){
	if (pos == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, map[i][j]);
			}
		}
		return;
	}

	int temp[20][20] = { 0, };
	copys(temp, map);

	up();
	bt(pos + 1);
	copys(map, temp);
	down();
	bt(pos + 1);
	copys(map, temp);
	left();
	bt(pos + 1);
	copys(map, temp);
	right();
	bt(pos + 1);
	copys(map, temp);
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
		}
	}

	bt(0);
	printf("%d\n", ans);
}