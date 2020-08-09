#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool alphabet[26];

int solution(string skill, vector<string> skill_trees) {
	int answer = 0;
	memset(alphabet, false, sizeof(alphabet));
	for (int i = 0; i < skill.length(); i++) {
		int index = skill[i] - 'A';
		alphabet[index] = true;
	}

	for (int i = 0; i < skill_trees.size(); i++) {
		string s = skill_trees[i];
		int index = 0, cnt = 0;
		bool flag = true;
		for (int j = 0; j < s.length(); j++) {
			index = s[j] - 'A';
			if (alphabet[index]) {
				if (cnt != skill.find(s[j])) {
					flag = false;
					break;
				}
				else cnt++;
			}
		}
		if (flag) answer++;
	}
	return answer;
}