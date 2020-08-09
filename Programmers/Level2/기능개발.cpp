#include <string>
#include <vector>

using namespace std;
vector<int> solution(vector<int> progresses, vector<int> speeds) {
	vector<int> answer;
	vector<int> days;

	for (int i = 0; i < speeds.size(); i++) {
		int progress = progresses[i];
		int speed = speeds[i];
		int day;
		int remainder = (100 - progress) % speed;
		if (remainder == 0) day = (100 - progress) / speed;
		else day = (100 - progress) / speed + 1;
		days.push_back(day);
	}

	for (int i = 1; i < days.size(); i++) {
		if (days[i - 1] > days[i]) days[i] = days[i - 1];
	}

	int a = days[0], cnt = 0;

	for (int i = 0; i < days.size(); i++) {
		if (a == days[i]) cnt++;
		else {
			answer.push_back(cnt);
			cnt = 1;
			a = days[i];
		}
	}
	answer.push_back(cnt);

	return answer;
}