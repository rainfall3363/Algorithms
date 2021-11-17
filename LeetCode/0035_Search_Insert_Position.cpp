class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int high = nums.size() - 1;
        int low = 0;
        int mid;
        
        while (low <= high) {
            mid = (low + high) / 2;
            if (nums[mid] > target) {
                high = mid - 1;
            }
            else if (nums[mid] < target) {
                low = mid + 1;   
            }
            else {
                break;
            }
        }
        
        if (low > high) {
            mid = low;
        }
        return mid;
    }
};
