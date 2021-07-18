#include <string>
#include <vector>

using namespace std;

bool oneLetterDiff(string, string);
void dfs(vector<string>, bool*, int, string, string, int);
int minCnt = 50;

int solution(string begin, string target, vector<string> words) {
    bool* visited = new bool[words.size()];
    for (int i = 0; i < words.size(); i++) {
        visited[i] = false;
    }
    
    dfs(words, visited, words.size(), target, begin, 0);
    
    if (minCnt == 50) {
        minCnt = 0;
    }
    
    delete[] visited;
    return minCnt;
}

bool oneLetterDiff(string a, string b) {
    bool result = false;
    int diffCnt = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a.at(i) - b.at(i) == 0) {
            continue;
        }
        else {
            diffCnt++;
        }
    
        if (diffCnt > 1) {
            break;
        }
    }
    
    if (diffCnt == 1) {
        result = true;
    }
    
    return result;
}

void dfs (vector<string> words, bool* visited, int vsize, string target, string present, int cnt) {
    if (!present.compare(target)) {
        if (cnt < minCnt) {
            minCnt = cnt;
        }
        return;
    }
    
    bool* arr = new bool[vsize];
    for (int i = 0; i < vsize; i++) {
        arr[i] = visited[i];
    }
    
    for (int i = 0; i < vsize; i++) {
        if (!arr[i] && oneLetterDiff(present, words[i])) {
            arr[i] = true;
            // arr[i]가 다음 함수 호출에 영향을 미치는지 확인
            dfs(words, arr, vsize, target, words[i], cnt + 1);
            arr[i] = false;
        }
    }
    
    delete[] arr;   
}
