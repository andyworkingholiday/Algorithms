#include <vector>
#include <unordered_map>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    unordered_map<int, int> hashmap;
    for(auto elem : nums) {
        if(hashmap.find(elem)==hashmap.end())
            hashmap.insert(make_pair(elem,1));
    }
    
    int poketmons = hashmap.size();
    if(poketmons >= nums.size()/2) answer = nums.size()/2;
    else answer= poketmons;
    
    return answer;
}
