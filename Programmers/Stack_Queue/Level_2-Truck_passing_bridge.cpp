#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0;   // answer와 동일
    int current_weight = 0;
    int truckIdx = 0;
    // 시간과 무게를 기록하는 Queue (동시에 진행)  
    queue<int> q_weight;
    queue<int> q_time;
    
    do {
        if (q_time.front() == time) {
            q_time.pop();
            current_weight -= q_weight.front();
            q_weight.pop();
        }
        if (truckIdx < truck_weights.size() && current_weight + truck_weights[truckIdx] <= weight) {
            current_weight += truck_weights[truckIdx];
            q_weight.push(truck_weights[truckIdx]);
            q_time.push(time + bridge_length);
            truckIdx++;
        }
        time++;
    } while (!q_weight.empty());
        
    return time;
}
