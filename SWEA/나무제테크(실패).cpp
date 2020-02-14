#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


struct tree {
	int y, x, age;
};

bool operator< (tree a, tree b) {
	return (a.age > b.age);
}

priority_queue<tree> pq[2];

int n, m, k;
int robot[10][10];
int yangbun[10][10];
const int dy[] = { -1,0,1,-1,1,-1,0,1 };
const int dx[] = { -1,-1,-1,0,0,1,1,1 }; 

int main() {
	int cur = 0, next;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &robot[i][j]);
			yangbun[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		tree start;
		scanf("%d %d %d", &start.y, &start.x, &start.age);
		start.y -= 1, start.x -= 1;
		pq[cur].push(start);
	}

	while (k--) {
		next = (cur + 1) % 2;
		queue<tree> life;
		queue<tree> death;

		while (!pq[cur].empty()) {
			tree cur_tree = pq[cur].top();
			pq[cur].pop();
			if (yangbun[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				yangbun[cur_tree.y][cur_tree.x] -= cur_tree.age;
				tree next_tree;
				next_tree.y = cur_tree.y;
				next_tree.x = cur_tree.x;
				next_tree.age = cur_tree.age + 1;
				life.push(next_tree);
				pq[next].push(next_tree);
			}
			else {
				death.push(cur_tree);
			}
		}

		while (!death.empty()) {
			tree cur_tree = death.front();
			death.pop();
			yangbun[cur_tree.y][cur_tree.x] += (cur_tree.age / 2);
		}

		while (!life.empty()) {
			tree cur_tree = life.front();
			life.pop();
			if ((cur_tree.age) % 5 == 0) {
				for (int dir = 0; dir < 8; dir++) {
					tree next_tree;
					next_tree.y = cur_tree.y + dy[dir];
					next_tree.x = cur_tree.x + dx[dir];
					next_tree.age = 1;
					if (next_tree.y<0 || next_tree.x <0 ||
						next_tree.y>n - 1 || next_tree.x>n - 1) continue;

					pq[next].push(next_tree);
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				yangbun[i][j] += robot[i][j];
			}
		}

		cur = next;
	}

	printf("%d\n", pq[next].size());

	return 0;
}