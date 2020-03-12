#include<iostream>
#include<algorithm>
using namespace std;

int ans, cnt;
int paper[11][11];
int paper_cnt[6];

bool pa_ch(int x, int y, int sizee) {
	for (int Y = y; Y < y + sizee; Y++) {
		for (int X = x; X < x + sizee; X++) {
			if (paper[Y][X] == 0)
				return false;
		}
	}
	return true;
}

void dfs(int ans_temp, int x, int y, int cnt_temp) {
	if (ans_temp > ans) return;
	if (cnt_temp == cnt) {
		ans = ans_temp;
		return;
	}
	if (ans_temp == 25) return;
	bool out = false;
	for (int Y = y; Y < 10; Y++) {
		for (int X = x; X < 10; X++) {
			if (paper[Y][X] == 1) {
				out = true;
				for (int i = 5; i >= 1; i--) { //1x1부터 5x5까지 탐색
					if (paper_cnt[i] == 0) continue;
					if (paper_cnt[i] == 0 && i == 1) return;
					if (!pa_ch(X, Y, i)) continue;

					paper_cnt[i]--;
					int gob = i * i;
					for (int YY = Y; YY < Y + i; YY++) {
						for (int XX = X; XX < X + i; XX++) {
							paper[YY][XX] = 0;
						} //for XX
					} // for YY

					dfs(ans_temp + 1, X, Y, cnt_temp + gob);

					paper_cnt[i]++;
					for (int YY = Y; YY < Y + i; YY++) {
						for (int XX = X; XX < X + i; XX++) {
							paper[YY][XX] = 1;
						}//for XX
					}//for YY

				}  //for i
			} //if paper
			if (out == true) break;
		} //for X
		if (out == true) break;
		x = 0;
	} //for Y
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cnt = 0;
	for (int i = 1; i < 6; i++) paper_cnt[i] = 5; //색종이 갯수 넣기

	for (int Y = 0; Y < 10; Y++) {
		for (int X = 0; X < 10; X++) {
			scanf("%d", &paper[Y][X]);
			//cin >> paper[Y][X];
			if (paper[Y][X] == 1) cnt++;
		}
	}
	ans = 40;
	dfs(0, 0, 0, 0);
	if (ans == 40)
		printf("-1");
	//cout << "-1";
	else
		printf("%d", ans);
	//cout << ans;
}
