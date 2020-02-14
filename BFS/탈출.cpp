#include <iostream>
#include <cstring>
#include <queue>
#define MAX 51
using namespace std;

int R, C, answer;
char map[MAX][MAX];
bool water[MAX][MAX];
int bieber[MAX][MAX];
queue<pair<int, int>> q;
queue<pair<int, int>> wq;
int dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,-1,1 };

int bfs(int y, int x) {
	q.push(pair<int, int>(y, x));
	bieber[y][x] = 1;
	while (!q.empty()) {
		int wsize = wq.size();
		while (wsize--) {
			int wy = wq.front().first;
			int wx = wq.front().second;
			wq.pop();
			for (int i = 0; i < 4; i++) {
				int nwy = wy + dy[i], nwx = wx + dx[i];
				if (nwy<0 || nwy>R - 1 || nwx<0 || nwx>C - 1) continue;
				if (map[nwy][nwx] == 'D' || map[nwy][nwx] == 'X' || water[nwy][nwx]) continue;
				wq.push(pair<int, int>(nwy, nwx));
				water[nwy][nwx] = true;
				map[nwy][nwx] = '*';
			}
		}

		int bsize = q.size();
		while (bsize--) {
			int by = q.front().first;
			int bx = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				int nby = by + dy[i], nbx = bx + dx[i];
				if (map[nby][nbx] == 'D') return bieber[by][bx];
				if (nby <0 || nby >R - 1 || nbx<0 || nbx>C - 1) continue;
				if (map[nby][nbx] == '.' && bieber[nby][nbx] == 0) {
					bieber[nby][nbx] = bieber[by][bx] + 1;
					q.push(pair<int, int>(nby, nbx));
				}

			}

		}
		
	}
	return -1;
	
}


int main() {
	scanf("%d %d", &R, &C);
	for (int i = 0; i < R; i++)
		scanf("%s", map[i]);
	int start_x, start_y;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'S') start_y = i, start_x = j;
			else if (map[i][j] == '*') {
				water[i][j] = true;
				wq.push(pair<int, int>(i, j));
			}			
		}
	}
	answer=bfs(start_y, start_x);
	if(answer==-1) printf("KAKTUS\n"); 
	else printf("%d\n", answer);
	return 0;
}