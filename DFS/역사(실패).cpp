#include <iostream>
#include <vector>
#define MAX 401
using namespace std;

int n, k, s;
vector<int> v[MAX][2];
bool down_flag = false, up_flag = false;

bool dfs_down(int acc1, int acc2) {
	if (acc1 == acc2) {
		down_flag = true;
		return down_flag;
	}

	for (int i = 0; i < v[acc1][0].size(); i++) {
		dfs_down(v[acc1][0][i], acc2);
	}

	return down_flag;
}

bool dfs_up(int acc1, int acc2) {
	if (acc1 == acc2) {
		up_flag = true;
		return down_flag;
	}

	for (int i = 0; i < v[acc1][1].size(); i++) {
		dfs_up(v[acc1][1][i], acc2);
	}

	return up_flag;
}


int main() {
	scanf("%d %d", &n, &k);
	for (int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		v[a][0].push_back(b);
		v[b][1].push_back(a);
	}

	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		int a, b;
		down_flag = false, up_flag = false;
		scanf("%d %d", &a, &b);
		if (dfs_down(a, b)) printf("-1\n");
		else if (dfs_up(a, b)) printf("1\n");
		else printf("0\n");
	}
	return 0;
}