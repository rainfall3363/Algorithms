#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int>);
bool compare(string, string);

int main() {
	vector<int> input1{ 3, 30, 34,	5, 9 };
	vector<int> input2{ 6, 10, 2 };
	vector<int> input3{ 0, 0, 0, 0, 0 };

	cout << solution(input1) << endl;
	
	return 0;
}

string solution(vector<int> numbers) {
	string answer = "";
	
	vector<string> answerStr;
	for (int i = 0; i < numbers.size(); i++) {
		answerStr.push_back(to_string(numbers[i]));
	}
	
 	// compare 함수 직접 정의
	sort(answerStr.begin(), answerStr.end(), compare);


	for (int i = answerStr.size() - 1; i >= 0; i--) {
		answer += answerStr[i];
	}

	if (answer.at(0) == '0') {
		answer = "0";
	}

	return answer;
}

bool compare(string a, string b) {
	if (a.length() == b.length()) {
		return a < b;
	}
	else {
		return a + b < b + a;
	}
}
