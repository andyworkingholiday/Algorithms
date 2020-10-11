#include <vector>
#include <string.h>
#include <queue>
#include <iostream>
using namespace std;

int check[20001];
int maxs;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<vector<int>> v(n+1);
    memset(check, 0, sizeof(check));
    for(auto elem : edge) {
        v[elem[0]].push_back(elem[1]);
        v[elem[1]].push_back(elem[0]);
    }
    
    queue<int> q;
    q.push(1);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        for(int i=0; i<v[cur].size(); i++) {
            if(check[v[cur][i]]!=0) continue;
            check[v[cur][i]] = check[cur] + 1;
            maxs = check[v[cur][i]] > maxs ? check[v[cur][i]] : maxs;
            q.push(v[cur][i]);
        }
    }
    
    for(int i=2; i<=n; i++) {
        if(check[i]==maxs) answer++;
    }
    
    return answer;
}
