#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int answer = 10001;
bool check[50];

void dfs(string a, string b, vector<string> words, int cnt) {
    if(a==b) {
        answer = min(answer, cnt);
        return;
    }
    
    for(int i=0; i<words.size(); i++) {
        if(check[i]) continue;
        int charcnt = 0;
        for(int j=0; j<words[i].length(); j++) {
            if(a[j] != words[i][j])
                charcnt++;
        }
        
        if(charcnt==1) {
            check[i] = true;
            dfs(words[i], b, words, cnt+1);
            check[i] = false;
        }
    }
    
}

int solution(string begin, string target, vector<string> words) {
    bool flag = false;
    for(int i=0; i<words.size(); i++) {
        if(target == words[i]) {
            flag = true;
            break;
        }
    }
    
    if(flag) {
        dfs(begin, target, words, 0);
    }
    
    else
        answer = 0;
    
    if(answer==10001) answer = 0;
    return answer;
}
