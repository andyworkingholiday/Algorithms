#include <iostream>
#include <algorithm>
#define MAX 21
using namespace std;

int R, C, answer;
char map[MAX][MAX];
int check[MAX][MAX];
bool alphabet[26];
int dx[] = { -1,1,0,0 }, dy[] = { 0,0,-1,1 };

void backtrack(int y, int x, int dist) {
	answer = max(answer, dist);
	check[y][x] = 1;
	alphabet[map[y][x] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i], nx = x + dx[i];
		if (ny <0 || ny>R - 1 || nx<0 || nx>C - 1) continue;
		if (!check[ny][nx] && !alphabet[map[ny][nx] - 'A'])
			backtrack(ny, nx, dist + 1);
	}
	check[y][x] = 0;
	alphabet[map[y][x] - 'A'] = false;
}
int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", &map[i]);
	backtrack(0, 0, 1);
	printf("%d\n", answer);
	return 0;
}