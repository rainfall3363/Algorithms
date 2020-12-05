#include <string>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> q;
    int day = 0;
    int cnt = 0;
    
    for (int i = 0; i < progresses.size(); i++) {
        q.push(progresses[i]);
    }
  
    for (int i = 0; i < progresses.size(); i++) {
        if ((day * speeds[i]) + q.front() >= 100) {
            q.pop();
            cnt++;
            // 마지막 progesses를 처리하기 위해 추가
            if (i == progresses.size() - 1) {
               answer.push_back(cnt);
            }
            continue;
        }
        else {
            if (cnt) {
                answer.push_back(cnt);
                cnt = 0;
            }
        }
        
        day = (int)ceil((100.0 - q.front()) / speeds[i]);
        q.pop();
        cnt++;
        
        // 마지막 progesses를 처리하기 위해 추가
        if (i == progresses.size() - 1) {
               answer.push_back(cnt);
        }
    }
    
    return answer;
}
