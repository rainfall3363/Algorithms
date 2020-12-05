#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<vector<int>> supo{{1,2,3,4,5}, {2,1,2,3,2,4,2,5}, {3,3,1,1,2,2,4,4,5,5}};
    vector<int> correct(supo.size());
    int supoIdx = 0;
    int big = 0;
    
    for (int i = 0; i < supo.size(); i++) {
        supoIdx = 0;
        for (int j = 0; j < answers.size(); j++) {
            if (answers[j] == supo[i][supoIdx]) {
                correct[i]++;
            }   
            supoIdx++;
            if (supoIdx == supo[i].size()) {
                supoIdx = 0;
            }
        } 
    }
    
    for(int i = 0; i < supo.size(); i++) {
        if (big <= correct[i]) {
            big = correct[i];
        }
    }
    for (int i = 0; i < supo.size(); i++) {
        if (correct[i] == big) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
