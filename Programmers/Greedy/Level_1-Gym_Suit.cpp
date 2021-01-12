#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int *gymsuit = new int[n];
    for (int i = 0; i < n; i++) {
        gymsuit[i] = 1;
    }
    
    for (int i = 0; i < lost.size(); i++) {
        gymsuit[lost[i] - 1]--;
    }
    for (int i = 0; i < reserve.size(); i++) {
        gymsuit[reserve[i] - 1]++;
    }
    
    // 전 사람 확인 후 다음 사람 확인
    if (gymsuit[0] > 1 && gymsuit[1] == 0) {
        // 0번째 위치에 있는 사람은 다음 사람만 확인
        gymsuit[0]--;
        gymsuit[1]++;
    }
    for (int i = 1; i < n - 1; i++) {
        if(gymsuit[i] > 1) {
            if (gymsuit[i - 1] == 0) {
                gymsuit[i]--;
                gymsuit[i - 1]++;
            }
            else if (gymsuit[i + 1] == 0) {
                gymsuit[i]--;
                gymsuit[i + 1]++;
            }
        }
    }
    // 맨 뒤 차례 사람은 전 사람만 확인
    if (gymsuit[n - 1] > 1 && gymsuit[n - 2] == 0) {
        gymsuit[n - 1]--;
        gymsuit[n - 2]++;
    }
    
    for (int i = 0; i < n; i++) {
        if (gymsuit[i]) {
            answer++;
        }
    }
    
    return answer;
}
