#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string numbers);
bool isPrime(int num);
void combination(string, vector<int>, int, int);

vector<vector<int>> beforePermutation;
vector<int> permutation;

int solution(string numbers) {
    int answer = 0;
    
    for (int i = 1; i <= numbers.size(); i++) {
        vector<int> comb(i);
        combination(numbers, comb, 0, 0);
    }
    for (int i = 0; i < beforePermutation.size(); i++) {
        int temp = 0;
        int decimal = 1;
        sort(beforePermutation[i].begin(), beforePermutation[i].end());
        do {
            for (auto it = beforePermutation[i].begin(); it != beforePermutation[i].end(); it++) {
                temp += *it * decimal;
                decimal *= 10;   
            }
            permutation.push_back(temp);
            
            temp = 0;
            decimal = 1;
        } while (next_permutation(beforePermutation[i].begin(), beforePermutation[i].end()));
    }
    for (int i = 0; i < permutation.size() - 1; i++) {
        for (int j = i + 1; j < permutation.size(); j++) {
            if (permutation[i] == permutation[j]) {
                permutation[j] = 0;
            }
        }
    }
    for (int i = 0; i < permutation.size(); i++) {
        if (isPrime(permutation[i])) {
            answer++;
        }
    }
    
    return answer;
}

bool isPrime(int num) {
    if (num < 2) {
        return false;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

void combination(string str, vector<int> comb, int aIdx, int cIdx) {
    vector<int> tmp;
    if (cIdx == comb.size()) {
        for (int i = 0; i < comb.size(); i++) {
            tmp.push_back(comb[i]);
        }
        beforePermutation.push_back(tmp);
        tmp.clear();
        return;
    }
    else {
        for (int i = aIdx; i < str.size(); i++) {
            comb[cIdx] = str.at(i) - 48;
            combination(str, comb, i + 1, cIdx + 1);
        }
    }
}
