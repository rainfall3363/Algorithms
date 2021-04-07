#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string str = "";
    int answer;
    int num;
    cin >> num;
    vector<int> group(num, 0);
    vector<vector<int>> words(num, vector<int>(1));

    for (int i = 0; i < num; i++) {
        cin >> str;
        for (int j = 0; j < str.length(); j++) {
            words[i].push_back((int)str.at(j));
        }
        sort(words[i].begin(), words[i].end());
    }
    
    answer = num;
    for (int i = 0; i < num - 1; i++) {
        if (group[i] != 1) {
            for (int j = i + 1; j < num; j++) {
                if (group[j] != 1 && words[i] == words[j]) {
                    group[j] = 1;
                    answer--;
                }
            }
        }
    }
    
    cout << answer;

    return 0;
}
