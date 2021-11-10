class Solution {
public:
    int arrangeCoins(int n) {
        int stairs = 0;
        long long sum = 0;
        
        while (1) {
            stairs++;
            sum += (long long)stairs;
            if (sum > n) {
                stairs--;
                break;
            }
            else if (sum == n) {
                break;
            }
        }
        
        return stairs;        
    }
};
