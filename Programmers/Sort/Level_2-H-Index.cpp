#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b);
int moreThan(int, vector<int>);

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end(), compare);

	answer = citations[0];
	while (1) {
		if (moreThan(answer, citations) <= answer) {
			break;
		}
		answer--;
	}

	return answer;
}

bool compare(int a, int b) {
	return a > b;
}

int moreThan(int n, vector<int> arr) {
	int cnt = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] >= n) {
			cnt++;
		}
	}

	return cnt;
}
