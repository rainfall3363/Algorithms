#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *stairs = new int[n]; 
    long long *dp = new long long[n];

    for (int i = 0; i < n; i++) {
        cin >> stairs[i];
        dp[i] = 0;
    }

    dp[0] = stairs[0];
    if (n > 1) {
        dp[1] = dp[0] + stairs[1];
    }
    if (n > 2) {
        dp[2] = max(stairs[0] + stairs[2], stairs[1] + stairs[2]);
    }
    if (n > 3) {
        for (int i = 3; i < n; i++) {
            dp[i] = max(dp[i - 3] + stairs[i - 1] + stairs[i], dp[i - 2] + stairs[i]);
        }
    }
    cout << dp[n - 1] << endl;

    delete[] dp;
    delete[] stairs;
    return 0;
}

/* DP
    1. 마지막 하나 전을 밟았을 경우
    2. 마지막 하나 전을 밟지 않았을 경우
    dp[n] = dp[n-3] + arr[n-1] + arr[n];
    dp[n] = dp[n-2] + arr[n];
    dp[n] = max(dp[n-3] + arr[n-1] + arr[n], dp[n-2] + arr[n]);
*/
