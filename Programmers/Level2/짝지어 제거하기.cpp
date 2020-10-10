#include <iostream>
#include <string>
#include <stack>
using namespace std;

int solution(string s) {
    int answer = 0;
    stack<char> temp;
    for(char c : s) {
        if(temp.empty() || temp.top()!=c) temp.push(c);
        else temp.pop();
    }
    if(temp.empty()) answer = 1;
    return answer;
}
