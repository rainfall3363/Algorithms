class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        
        vector<int> nums;
        long long decimal = 1;
        long long upperNum = 0;
            
        while (x / (decimal * 10) > 0)
            decimal *= 10;
        
        while (decimal > 0) {
            nums.push_back((int)(x / decimal) - upperNum);
            upperNum += nums.back();
            upperNum *= 10;
            decimal = decimal / 10;
        }
        for (int i = 0; i < (int)(nums.size() / 2); i++) {
            if (nums[i] != nums[nums.size() - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
};
