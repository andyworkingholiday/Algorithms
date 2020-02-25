#include <iostream>
#include <vector>
#include <algorithm>
#define MAX  987654321
using namespace std;

int n, m, map[50][50], ans;
int real_ans = MAX;
vector<pair<int, int>> v;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

void pick_chick(int pos) {
	if (chicken.size() == m) {
		ans = 0;
		for (int i = 0; i < house.size(); i++) {
			int mins = MAX;
			for (int j = 0; j < m; j++) {
				int distance = abs(house[i].first - chicken[j].first) + abs(house[i].second - chicken[j].second);
				mins = min(distance, mins);
			}
			ans += mins;
		}

		real_ans = min(ans, real_ans);
		return;
 	}

	for (int i = pos; i < v.size(); i++) {
		chicken.push_back(v[i]);
		pick_chick(i + 1);
		chicken.pop_back();
	}
}


int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 2) v.push_back({ i,j });
			else if (map[i][j] == 1) house.push_back({ i,j });
		}
	}
	pick_chick(0);
	printf("%d\n", real_ans);
	return 0;
}