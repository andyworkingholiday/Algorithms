#include <iostream>
#include <deque>
using namespace std;

int N, K, L;
int apple[100][100];
bool check[100][100];

const int dy[] = { 0,1,0,-1 }, dx[] = { 1,0,-1,0 };

int main() {
	deque<pair<int, char>> dir;
	deque<pair<int, int>> snake;

	scanf("%d %d", &N, &K);
	for (int i = 0; i < K; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		apple[a - 1][b - 1] = 1;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; i++) {
		int x;
		char c;
		scanf("%d %c", &x, &c);
		dir.push_back({ x,c });
	}

	int sec = 0, idx = 0;
	snake.push_back({ 0,0 });
	check[0][0] = true;

	while (1) {
		sec++;
		pair<int, int> before = snake.back();
		pair<int, int> head = { before.first + dy[idx], before.second + dx[idx] };
		if (check[head.first][head.second] || head.first <0 || head.first>N - 1 || head.second <0 || head.second>N - 1) {
			printf("%d\n", sec);
			break;
		}

		check[head.first][head.second] = true;
		snake.push_back(head);

		if (apple[head.first][head.second]) {
			apple[head.first][head.second] = 0;
		}
		else {
			check[snake.front().first][snake.front().second] = false;
			snake.pop_front();
		}

		if (dir.size() > 0 && dir.front().first == sec) {
			if (dir.front().second == 'L')
				idx = (idx + 3) % 4;
			else
				idx = (idx + 1) % 4;
			dir.pop_front();
		}

	}
	return 0;
}