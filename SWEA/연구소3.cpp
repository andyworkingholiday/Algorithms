#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N, M, empty_place;
int mins = 99999;
int map[50][50];
int check[50][50];
const int dy[] = { -1,1,0,0 }, dx[] = { 0,0,-1,1 };
vector<pair<int, int>> virus;
vector<pair<int, int>> pick;

void bfs() {	
	queue<pair<int, int>> q;
	memset(check, -1, sizeof(check));

	for (int i = 0; i < M; i++) {
		q.push(pick[i]);
		check[pick[i].first][pick[i].second] = 0;
	}

	int infect_area = 0;
	int total_time = 0;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ny = cy + dy[dir];
			int nx = cx + dx[dir];
			if (ny<0 || ny>N - 1 || nx<0 || nx>N - 1) continue;
			if (map[ny][nx] != 1 && check[ny][nx]==-1) {
				q.push({ ny,nx });
				check[ny][nx] = check[cy][cx] + 1;
				if (map[ny][nx] == 0) {
					infect_area++;
					total_time = check[ny][nx];
				}
			}		
		}
	}

	if (infect_area == empty_place) {
		mins = min(total_time, mins);
	}
	
}

void pick_virus(int pos, int cnt) {
	if (cnt == M) {
		bfs();
		return;
	}

	for (int i = pos; i < virus.size(); i++) {
		pick.push_back(virus[i]);
		map[virus[i].first][virus[i].second] = 3;
		pick_virus(i + 1, cnt + 1);
		map[virus[i].first][virus[i].second] = 2;
		pick.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) virus.push_back({ i,j });
			if (map[i][j] == 0) empty_place++;
		}
	}

	pick_virus(0, 0);

	if (mins == 99999) printf("-1\n");
	else printf("%d\n", mins);
	return 0;
}