#include <string>
#include <vector>
using namespace std;

bool check[200];

void dfs(int pos, vector<vector<int>>& v, int n) {
    check[pos] = true;
    for(int i = 0; i < n; i++) {
        if(check[i] || v[pos][i]==0) continue;
        dfs(i, v, n);
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0; i < n; i++) {
        if(check[i]) continue;
        answer++;
        dfs(i, computers, n);
    }
    
    return answer;
}
