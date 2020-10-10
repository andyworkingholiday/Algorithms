#include <string>
#include <vector>

using namespace std;

int lcm(int a, int b) {
    int larger = a > b ? a : b;
    for(int i = larger; i<=a*b; i++) {
        if(i%a==0 && i%b==0)
            return i;
    }
}

int solution(vector<int> arr) {
    int answer = arr[0];
    for(int i=1; i<arr.size(); i++) {
        answer = lcm(answer, arr[i]);
    }
    
    return answer;
}
