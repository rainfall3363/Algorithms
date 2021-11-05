void jumpCount(vector<int>& nums, int idx, int& count) {    
    int jumpPt = idx;    
    
    if (nums.size() == 1) {
        return;
    }
    if (nums[idx] + idx >= nums.size() - 1) {
        count++;
        return;
    }
    
    for (int i = idx; i <= idx + nums[idx]; i++) {
        if (nums[jumpPt] + jumpPt <= nums[i] + i) {
            jumpPt = i;
        }
    }
    
    jumpCount(nums, jumpPt, ++count);
}

class Solution {
public:
    int jump(vector<int>& nums) {
        int count = 0;
        
        jumpCount(nums, 0, count);
        
        return count;
    }
};
