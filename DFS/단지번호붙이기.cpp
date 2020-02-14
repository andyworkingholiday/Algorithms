#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, danzisu = 0;
int answer = 1;
const int MAX = 26;
int danzi[MAX][MAX];
bool check[MAX][MAX];
vector<int> house;
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1) continue;
		if (danzi[ny][nx] && !check[ny][nx]) {
			dfs(ny, nx);
			answer++;
		}
	}
}

void solve() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (danzi[i][j] && !check[i][j]) {
				dfs(i, j);
				danzisu++;
				house.push_back(answer);
				answer = 1;
			}
		}
	}

	sort(house.begin(), house.end());
	printf("%d\n", danzisu);
	for (int i = 0; i < house.size(); i++)
		printf("%d\n", house[i]);
}


int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &danzi[i][j]);
		}
	}
	solve();

}