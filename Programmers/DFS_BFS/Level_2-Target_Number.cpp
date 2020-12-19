#include <string>
#include <vector>

using namespace std;

void dfs(char ch, vector<int> numbers, int target, int sum, int idx, int &answer) {
	if (ch == '+') {
		sum += numbers[idx];
	}
	else {
		sum -= numbers[idx];
	}

	if (idx == numbers.size() - 1) {
		if (sum == target) {
			answer++;
		}
		return;
	}

	dfs('+', numbers, target, sum, ++idx, answer);
	dfs('-', numbers, target, sum, idx, answer);
}

int solution(vector<int> numbers, int target) {
	int answer = 0;
	int sum = 0;
	int idx;

	idx = 0;
	dfs('+', numbers, target, sum, idx, answer);
	idx = 0;
	dfs('-', numbers, target, sum, idx, answer);

	return answer;
}
