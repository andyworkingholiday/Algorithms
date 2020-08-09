#include <string>
#include <vector>
#include <queue>
using namespace std;

struct truck {
	int weight;
	int step;
};

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0, total_weight = 0, cnt = 0;
	int truck_size = truck_weights.size();
	queue<truck> going;
	while (1) {
		if (cnt == truck_size) break;
		int sizes = going.size();
		for (int i = 0; i < sizes; i++) {
			truck a = going.front();
			going.pop();
			if (a.step == bridge_length - 1) {
				total_weight -= a.weight;
				cnt++;
			}

			else going.push({ a.weight, a.step + 1 });
		}

		if (truck_weights.size() >= 1 && total_weight + truck_weights[0] <= weight) {
			total_weight += truck_weights[0];
			going.push({ truck_weights[0],0 });
			truck_weights.erase(truck_weights.begin());
		}
		answer++;
	}

	return answer;
}