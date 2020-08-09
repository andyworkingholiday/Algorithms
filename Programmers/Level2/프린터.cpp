#include <string>
#include <vector>
#include <queue>
using namespace std;

struct printer {
	int index;
	int priority;
};

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<printer> repr, order;
	for (int i = 0; i < priorities.size(); i++) {
		repr.push_back({ i, priorities[i] });
	}

	while (!repr.empty()) {
		printer a = repr[0];
		repr.erase(repr.begin());
		bool flag = true;
		for (int i = 0; i < repr.size(); i++) {
			if (repr[i].priority > a.priority) {
				repr.push_back(a);
				flag = false;
				break;
			}
		}
		if (flag) order.push_back(a);
	}

	for (int i = 0; i < order.size(); i++) {
		if (location == order[i].index) {
			answer = i + 1;
			break;
		}
	}

	return answer;
}