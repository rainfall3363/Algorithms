#include <string>
#include <vector>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    bool* isParticipate = new bool[participant.size()];
    for (int i = 0; i < participant.size(); i++) {
        isParticipate[i] = false;
    }
    
    for (int i = 0; i < completion.size(); i++) {
        for (int j = 0; j < participant.size(); j++) {
            if (!isParticipate[j] && !completion[i].compare(participant[j])) {
                isParticipate[j] = true;
                break;
            }
        }
    }
    
    for (int i = 0; i < participant.size(); i++) {
        if (!isParticipate[i]) {
            answer += participant[i];
        }
    }

    return answer;
}
