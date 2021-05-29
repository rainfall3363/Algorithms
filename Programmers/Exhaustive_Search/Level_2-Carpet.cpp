#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int carpet = brown + yellow;

    for (int i = carpet - 1; i > 0; i--) {
        if (carpet % i == 0 && (i - 2) * (carpet / i - 2) == yellow) {
                answer.push_back(i);
                answer.push_back(carpet / i);
                break;
            }
        }
    }

    return answer;
}
