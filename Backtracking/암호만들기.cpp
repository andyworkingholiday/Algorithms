#include <iostream>
#include <string>
#include <algorithm>
#define MAX 16
using namespace std;


int L, C;
char A[MAX];

void dfs(int index, int cnt, int mo, int ja, string s) {
	if (cnt == L) {
		if (mo >= 1 && ja >= 2)
			cout << s << endl;
		return;
	}
	if (index == C) return;
	if (A[index] == 'a' || A[index] == 'e' || A[index] == 'i' || A[index] == 'o' || A[index] == 'u') {
		dfs(index + 1, cnt + 1, mo + 1, ja, s + A[index]);
	}
	else dfs(index + 1, cnt + 1, mo, ja + 1, s + A[index]);
	dfs(index + 1, cnt, mo, ja, s);
}

int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; i++)
		scanf(" %c", &A[i]);
	sort(A, A + C);
	dfs(0, 0, 0, 0, "");
	return 0;


}