#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int u;
    stack<int> route;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < n; i++) {
        if (visited[i]) {
            continue;
        }
        route.push(i);
        while (!route.empty()) {
            u = route.top();
            route.pop();
            for (int j = 0; j < n; j++) {
                if (computers[u][j] && !visited[j]) {
                    visited[j] = true;
                    route.push(j);
                }          
            }        
        }            
        answer++;
    }
    
    delete[] visited;
    return answer;
}
