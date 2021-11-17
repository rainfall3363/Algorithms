class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> numOfUniquePaths(m, vector<int>(n, 0));
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0) {
                    numOfUniquePaths[i][j] = 1;
                }
                else {
                    numOfUniquePaths[i][j] = numOfUniquePaths[i - 1][j] + numOfUniquePaths[i][j - 1];
                }
            }
        }
        
        return numOfUniquePaths[m - 1][n - 1];
    }
};
