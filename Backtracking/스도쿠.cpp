#include <iostream>
using namespace std;

int sudoku[9][9];
bool stop;

bool promise(int num, int y, int x) {
	int ry = y / 3 * 3, rx = x / 3 * 3;
	for (int i = 0; i < 9; i++)
		if (sudoku[y][i] == num || sudoku[i][x] == num) return false;
	for (int i = ry; i < ry + 3; i++) {
		for (int j = rx; j < rx + 3; j++)
			if (sudoku[i][j] == num) return false;
	}
	return true;
}

void go() {
	if (stop) return;

	bool flag = false;
	int x = 0, y = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (sudoku[i][j] == 0) {
				flag = true;
				y = i, x = j;
			}
			if (flag) break;
		}
		if (flag) break;
	}

	if (!flag) {
		stop = true;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++)
				printf("%d ", sudoku[i][j]);
			printf("\n");
		}

		return;
	}
		

	for (int i = 0; i < 10; i++) {
		if (promise(i, y, x)) {
			sudoku[y][x] = i;
			go();
			sudoku[y][x] = 0;
		}
	}



}


int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++)
			scanf("%d", &sudoku[i][j]);
	}

	go();
	return 0;

}