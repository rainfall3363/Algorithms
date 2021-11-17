class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station = -1;
        int gasTank = 0;
        
        for (int i = 0; i < gas.size(); i++) {
            if (gas[i] < cost[i]) {
                continue;
            }
            gasTank = 0;
            station = i;
            
            do {
                if (station == gas.size()) {
                    station -= gas.size();
                }
                gasTank += gas[station];
                if (gasTank < cost[station]) {
                    station = -1;
                    break;
                }
                else {
                    gasTank -= cost[station];
                }
                station++;
                // 예외 케이스
                if (i == 0 && station == gas.size()) {
                    break;
                }
            } while (station != i);
            
            if (station >= 0) {
                break;
            }
        }
        // 예외 케이스
        if (station == gas.size()) {
            station = 0;
        }
        return station;
    }
};
