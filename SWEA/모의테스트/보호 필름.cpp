#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool ff = false;
int D, W, K;
int map[13][20];
int temp[13][20];
vector<int> v;

bool countcell() {
	int a = 0;
	for (int j = 0; j < W; j++) {
		int cnt = 1;
		bool flag = false;
		for (int i = 1; i < D; i++) {
			if (map[i - 1][j] == map[i][j]) cnt++;
			else cnt = 1;
			if (cnt >= K) {
				flag = true;
				a++;
				break;
			}
		}
		
		if (!flag) return false;
	}

	if (a == W) return true;
}

void abab(int pos) {
	if (!ff) {
		if (pos == v.size()) {
			ff = countcell();
			return;
		}

		for (int i = 0; i < W; i++) {
			map[v[pos]][i] = 0;
		}

		abab(pos + 1);

		for (int i = 0; i < W; i++) {
			map[v[pos]][i] = 1;
		}

		abab(pos + 1);
	}
	return;
}

void pick(int a, int idx) {
	if (!ff) {
		if (v.size() == a) {
			for (int i = 0; i < D; i++) {
				for (int j = 0; j < W; j++) {
					map[i][j] = temp[i][j];
				}
			}
			abab(0);
			return;
		}

		for (int i = idx; i < D; i++) {
			v.push_back(i);
			pick(a, i + 1);
			v.pop_back();
		}
	}
	return;
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int t = 1; t <= testcase; t++) {
		int ans = 0;
		ff = false;
		v.clear();
		scanf("%d %d %d", &D, &W, &K);
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				scanf("%d", &map[i][j]);
				temp[i][j] = map[i][j];
			}
		}

		bool first = countcell();
		int i;

		if (K==1 || first) ans = 0;
		else {
			for (i = 1; i <= K; i++) {
				v.clear();
				pick(i, 0);
				if (ff) {
					ans = i;
					break;
				}
			}
		}
		printf("#%d %d\n", t, ans);
	}
	return 0;
}