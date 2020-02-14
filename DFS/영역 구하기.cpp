#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

int M, N, K, answer;
int temp = 1;
vector<int> v;
const int MAX = 101;
int rec[MAX][MAX];
bool check[MAX][MAX];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	check[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (nx<0 || nx>N - 1 || ny<0 || ny>M - 1) continue;
		if (rec[ny][nx] && !check[ny][nx]) {
			dfs(ny, nx);
			temp++;
		}
	}
}

void solve() {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (rec[i][j] && !check[i][j]) {
				dfs(i, j);
				answer++;
				v.push_back(temp);
				temp = 1;
			}
		}
	}
	sort(v.begin(), v.end());
	printf("%d\n", answer);
	for (int i = 0; i < answer; i++)
		printf("%d ", v[i]);
}

int main() {
	scanf("%d %d %d", &M, &N, &K);
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			rec[i][j] = 1;
		}
	}
	
	while (K--) {
		int x0, y0, x1, y1;
		scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
		for (int i = M-y1; i < M-y0; i++) {
			for (int j = x0; j < x1; j++) {
				rec[i][j] = 0;
			}
		}
	}
	solve();
	
}