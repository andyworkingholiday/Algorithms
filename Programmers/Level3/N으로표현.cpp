#include <string>
#include <vector>
using namespace std;
int answer = 10;

void dfs(int N, int number, int cnt, int sum) {
    if(sum==number) {
        answer = cnt < answer ? cnt: answer;
        return;
    }
    
    if(cnt>=9) return;
    if(cnt!=0 && sum==0) return;
    int temp = 0;
    for(int i=0; i<9-cnt; i++) {
        temp = 10 * temp + N;
        dfs(N, number, cnt+i+1, sum+temp);
        dfs(N, number, cnt+i+1, sum-temp);
        dfs(N, number, cnt+i+1, sum*temp);
        dfs(N, number, cnt+i+1, sum/temp);
    }
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(answer==10) answer = -1;
    return answer;
}
