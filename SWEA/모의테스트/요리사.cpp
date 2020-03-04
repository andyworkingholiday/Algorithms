#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

int N, ret;
int ans = 987654321;
int map[16][16];
bool arr[16];
vector<int> t;
vector<int> f;
vector<int> rt;
vector<int> rf;
int a, b, c, d;

void calculate(int pos, int cnt) {
	if (cnt == 2) {
		a += (map[rt[0]][rt[1]] + map[rt[1]][rt[0]]);
		b += (map[rf[0]][rf[1]] + map[rf[1]][rf[0]]);
		return;
	}

	for (int i = pos; i < t.size(); i++) {
		rt.push_back(t[i]);
		rf.push_back(f[i]);
		calculate(i + 1, cnt + 1);
		rt.pop_back();
		rf.pop_back();
	}

}



void bts(int pos, int cnt) {
	if (cnt==N/2) {
		t.clear();
		f.clear();
		a = 0, b = 0;
		for (int i = 0; i < N; i++) {
			if (arr[i]) t.push_back(i);
			else f.push_back(i);
		}		
		calculate(0, 0);

		if (c == b && d == a) {
			return;
		}

		c = a, d = b;
		ret = abs(a - b);
		ans = min(ans, ret);
		return;
	}

	for (int i = pos; i < N; i++) {
		arr[i] = true;
		bts(i + 1, cnt + 1);
		arr[i] = false;
	}
}

int main() {
	int testcase;
	scanf("%d", &testcase);
	for (int iter = 1; iter <= testcase; iter++) {
		memset(arr, false, sizeof(false));
		ans = 987654321, ret = 0;
		rt.clear(); rf.clear();
		t.clear(); f.clear();
		a = 0, b = 0, c = 0, d = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
			}
		}

		bts(0, 0);
		printf("#%d %d\n", iter, ans);
	}
	return 0;
}