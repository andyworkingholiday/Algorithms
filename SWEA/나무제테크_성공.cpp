#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


struct tree {
	int y, x, age;
};

bool cmp(tree& a, tree& b) {
	return (a.age < b.age);
}

tree init[100];
queue<tree> q[2];

int n, m, k;
int robot[10][10];
int yangbun[10][10];
const int dy[] = { -1,0,1,-1,1,-1,0,1 };
const int dx[] = { -1,-1,-1,0,0,1,1,1 };

int main() {
	int cur = 0, next = 0;
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
		start.y--, start.x--;
		init[i] = start;
	}

	sort(init, init + m, cmp);

	for (int i = 0; i < m; i++) {
		q[cur].push(init[i]);
	}
	
	queue<tree> birth;
	while (k--) {
		next = (cur + 1) % 2;
		queue<tree> life;
		queue<tree> death;

		while (!birth.empty()) {
			tree cur_tree = birth.front();
			birth.pop();
			if (yangbun[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				yangbun[cur_tree.y][cur_tree.x] -= cur_tree.age;
				tree next_tree;
				next_tree.y = cur_tree.y;
				next_tree.x = cur_tree.x;
				next_tree.age = cur_tree.age + 1;
				q[next].push(next_tree);
			}
			else {
				death.push(cur_tree);
			}
		}

		while (!q[cur].empty()) {
			tree cur_tree = q[cur].front();
			q[cur].pop();
			if (yangbun[cur_tree.y][cur_tree.x] >= cur_tree.age) {
				yangbun[cur_tree.y][cur_tree.x] -= cur_tree.age;
				tree next_tree;
				next_tree.y = cur_tree.y;
				next_tree.x = cur_tree.x;
				next_tree.age = cur_tree.age + 1;
				q[next].push(next_tree);

				if (next_tree.age % 5 == 0) {
					life.push(next_tree);
				}
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
			for (int dir = 0; dir < 8; dir++) {
				tree next_tree;
				next_tree.y = cur_tree.y + dy[dir];
				next_tree.x = cur_tree.x + dx[dir];
				next_tree.age = 1;
				if (next_tree.y<0 || next_tree.x <0 || next_tree.y>n - 1 || next_tree.x>n - 1) continue;
				birth.push(next_tree);
			}		
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				yangbun[i][j] += robot[i][j];
			}
		}

		cur = next;
	}

	printf("%d\n", q[next].size()+birth.size());
	return 0;
}