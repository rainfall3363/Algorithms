#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int erased = 0;
    // 내가 내 다음보다 작으면 나 삭제     
    for (int i = 0; i < number.size() - 1; i++) {
        if (erased == k) {
            break;
        }
        if (number.at(i) < number.at(i + 1)) {   
            number.erase(i, 1);
            i = -1;     // 처음부터 다시 확인
            erased++;
        }
    }
    // 이래도 안 끝나면 뒤에서부터 삭제
    if (erased != k) {
        number.erase(number.size() - 1 - erased, k - erased);
    }
    
    answer += number;
    return answer;
}
