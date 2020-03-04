#include <iostream>
#include <string>
using namespace std;

int N;
char command[2][1000];
char cube[6][3][3];
string color = "wyrogb";
//위아앞뒤왼오


// 3<-5 5<-4 4<-6 6<-3
// 


int ctoit(char a) {
	if (a == 'U') return 0;
	else if (a == 'D') return 1;
	else if (a == 'F') return 2;
	else if (a == 'B') return 3;
	else if (a == 'L') return 4;
	else return 5;
}

void rotate(char a, char b) {
	string triple = "abc";
	int k = ctoit(a);
	char temp1, temp2;

	switch (b) {
	case '+':
		temp1 = cube[k][0][0];
		cube[k][0][0] = cube[k][2][0];
		cube[k][2][0] = cube[k][2][2];
		cube[k][2][2] = cube[k][0][2];
		cube[k][0][2] = temp1;
		temp2 = cube[k][0][1];
		cube[k][0][1] = cube[k][1][0];
		cube[k][1][0] = cube[k][2][1];
		cube[k][2][1] = cube[k][1][2];
		cube[k][1][2] = temp2;
		break;

	case '-':
		temp1 = cube[k][0][0];
		cube[k][0][0] = cube[k][0][2];
		cube[k][0][2] = cube[k][2][2];
		cube[k][2][2] = cube[k][2][0];
		cube[k][2][0] = temp1;
		temp2 = cube[k][0][1];
		cube[k][0][1] = cube[k][1][2];
		cube[k][1][2] = cube[k][2][1];
		cube[k][2][1] = cube[k][1][0];
		cube[k][1][0] = temp2;
		break;
	}

	switch (a) {
	case 'U':
		if (b == '+') {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][0][i];
				cube[2][0][i] = cube[5][0][i];
				cube[5][0][i] = cube[3][0][i];
				cube[3][0][i] = cube[4][0][i];
				cube[4][0][i] = triple[i];
			}
		}

		else {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][0][i];
				cube[2][0][i] = cube[4][0][i];
				cube[4][0][i] = cube[3][0][i];
				cube[3][0][i] = cube[5][0][i];
				cube[5][0][i] = triple[i];
			}
		} break;

	case 'D':
		if (b == '+') {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][2][i];
				cube[2][2][i] = cube[4][2][i];
				cube[4][2][i] = cube[3][2][i];
				cube[3][2][i] = cube[5][2][i];
				cube[5][2][i] = triple[i];
			}
		}

		else {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][2][i];
				cube[2][2][i] = cube[5][2][i];
				cube[5][2][i] = cube[3][2][i];
				cube[3][2][i] = cube[4][2][i];
				cube[4][2][i] = triple[i];
			}
		} break;	

	// 4->0 0->5 5->1 1->4
	case 'F':
		if (b == '+') {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[4][i][2];
				cube[4][i][2] = cube[1][0][i];
				cube[1][0][i] = cube[5][2 - i][0];
				cube[5][2 - i][0] = cube[0][2][2 - i];
				cube[0][2][2 - i] = triple[i];
			}
		}

		else {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[4][i][2];
				cube[4][i][2] = cube[0][2][2 - i];
				cube[0][2][2 - i] = cube[5][2 - i][0];
				cube[5][2 - i][0] = cube[1][0][i];
				cube[1][0][i] = triple[i];
			}
		} break;

	case 'B':
		if (b == '+') {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[4][i][0];
				cube[4][i][0] = cube[0][0][2-i];
				cube[0][0][2 - i] = cube[5][2 - i][2];
				cube[5][2 - i][2] = cube[1][2][i];
				cube[1][2][i] = triple[i];
			}
		}

		else {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[4][i][0];
				cube[4][i][0] = cube[1][2][i];
				cube[1][2][i] = cube[5][2 - i][2];
				cube[5][2 - i][2] = cube[0][0][2 - i];
				cube[0][0][2 - i] = triple[i];
			}
		} break;

	// 2->1 1->3 3->0 0->2
	case 'L':
		if (b == '+') {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][i][0];
				cube[2][i][0] = cube[0][i][0];
				cube[0][i][0] = cube[3][2 - i][2];
				cube[3][2 - i][2] = cube[1][i][0];
				cube[1][i][0] = triple[i];
			}
		}

		else {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][i][0];
				cube[2][i][0] = cube[1][i][0];
				cube[1][i][0] = cube[3][2 - i][2];
				cube[3][2 - i][2] = cube[0][i][0];
				cube[0][i][0] = triple[i];
			}
		} break;

	case 'R':
		if (b == '+') {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][i][2];
				cube[2][i][2] = cube[1][i][2];
				cube[1][i][2] = cube[3][2 - i][0];
				cube[3][2 - i][0] = cube[0][i][2];
				cube[0][i][2] = triple[i];
			}
		}

		else {
			for (int i = 0; i < 3; i++) {
				triple[i] = cube[2][i][2];
				cube[2][i][2] = cube[0][i][2];
				cube[0][i][2] = cube[3][2 - i][0];
				cube[3][2 - i][0] = cube[1][i][2];
				cube[1][i][2] = triple[i];
			}
		} break;
	}
}


int main() {
	int test;
	scanf("%d", &test);
	while (test--) {
		scanf("%d", &N);

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					cube[i][j][k] = color[i];
				}
			}
		}


		for (int i = 0; i < N; i++) {
			string s;
			cin >> s;
			rotate(s[0], s[1]);
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				printf("%c", cube[0][i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}