#include <vector>
#include <iostream>
using namespace std;

int numbers[3001];
int answer = 0;

void Eratos() {
    for(int i=2; i<3001; i++) {
        numbers[i] = i;
    }
    
    for(int i=2; i<3001; i++) {
        if(numbers[i]==0) continue;
        for(int j = i+i; j<3001; j+=i) {
            numbers[j] = 0;
        }
    }
}

void dfs(vector<int>& v, int pos, int cnt, int sum) {
    if(cnt==3) {
        if(numbers[sum]!=0) answer++;
        return;
    }
    
    for(int i = pos; i<v.size(); i++) {
        dfs(v, i+1, cnt+1, sum+v[i]);
    }
}

int solution(vector<int> nums) {
    Eratos();
    dfs(nums, 0, 0, 0);
    return answer;
}
