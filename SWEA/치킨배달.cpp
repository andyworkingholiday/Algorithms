#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct yx {
	int y, x;
};

int N, M;
int chick_distance, answer = 99999;
int map[50][50];
vector<yx> pick_chick;
vector<yx> chicken_house;
vector<yx> house;

void calculate() {
	chick_distance = 0;
	for (int i = 0; i < house.size(); i++) {
		int distance = 100;
		for (int j = 0; j < pick_chick.size(); j++) {
			int ret = abs(house[i].y - pick_chick[j].y) + abs(house[i].x - pick_chick[j].x);
			distance = min(distance, ret);
		}
		chick_distance += distance;
	}
}

void pick(int pos, int cnt) {
	if (cnt == M) {
		calculate();
		answer = min(answer, chick_distance);
		return;
	}

	for (int i = pos; i < chicken_house.size(); i++) {
		pick_chick.push_back(chicken_house[i]);
		pick(i + 1, cnt + 1);
		pick_chick.pop_back();
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) chicken_house.push_back({ i,j });
			else if (map[i][j] == 1) house.push_back({ i,j });
		}
	}
	pick(0, 0);
	printf("%d\n", answer);
	return 0;
}