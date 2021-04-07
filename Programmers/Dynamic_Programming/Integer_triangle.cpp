#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<int> sum1, sum2;
    // sum1 - 전 줄까지의 누적합
    // sum2 - 이번 줄의 누적합
    
    // 하나 전 녀석의 내자리 + 내자리-1 값 중 더 큰놈과 나를 더해서 내 자리에 저장 반복 
    sum1.push_back(triangle[0][0]);
    for (int i = 1; i < triangle.size(); i++) {
        sum2.push_back(sum1[0] + triangle[i][0]);
        for (int j = 1; j < triangle[i].size() - 1; j++) {
            sum2.push_back(max(sum1[j - 1], sum1[j]) + triangle[i][j]);
        }
        sum2.push_back(sum1.back() + triangle[i].back());
        
        sum1.clear();
        sum1.assign(sum2.begin(), sum2.end());
        sum2.clear();
    }
    
    answer = *max_element(sum1.begin(), sum1.end());    
    
    return answer;
}
