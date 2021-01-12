#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int solution(vector<int> people, int limit) {
    int answer = 0;
    int *escaped = new int[people.size()];
    for (int i = 0; i < people.size(); i++) {
        escaped[i] = 0;
    }
    
    // 내림 차순 정렬
    sort(people.begin(), people.end(), compare);
    // 반복문 돌면서 더했을때 limit 보다 낮으면 채용 break;
    for (int i = 0; i < people.size() - 1; i++) {
        if (escaped[i] == 0) {
            for (int j = i + 1; j < people.size(); j++) {
                if (escaped[j] == 0 && people[i] + people[j] <= limit) {
                    escaped[i] = 1;
                    escaped[j] = 1;
                    answer++;
                    break;
                }
                // 남은 사람들 태워
                if (j == people.size() - 1) {
                    answer++;
                }
            }         
        }
    }
    // 위 반복문에서 i가 마지막 사람까지 가지 않기 때문에 확인해야함
    if (escaped[people.size() - 1] == 0) {
        answer++;
    }
    
    delete[] escaped;
    return answer;
}
