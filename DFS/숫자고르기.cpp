#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[101];
bool cycle[101];
bool check[101];
int cnt = 0;
vector<int> v;


void dfs(int node) {
	check[node] = true;
	int next_node = arr[node];
	if (!check[next_node]) dfs(next_node);
	else if(!cycle[next_node]) {
		v.push_back(node);
		for (int i = next_node; i != node; i = arr[i]) 
			v.push_back(i);		
	}
	cycle[node] = true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
	}
	for (int i = 1; i <= n; i++) {
		if (check[i] == 0) dfs(i);
	}

	printf("%d\n", v.size());
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
	return 0;

}