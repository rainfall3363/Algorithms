class KthLargest {
public:
    int k;
    vector<int> nums;
    
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        this->nums.clear();
        if (nums.size() > 0) {
            this->nums.assign(nums.begin(), nums.end());
            sort(this->nums.rbegin(), this->nums.rend());            
        }
    }
    
    int add(int val) {
        if (nums.size() < 2) {
            nums.push_back(val);
            sort(nums.rbegin(), nums.rend());
        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] <= val) {
                    nums.push_back(0);
                    for (int j = nums.size() - 1; j > i; j--) {
                        nums[j] = nums[j - 1];
                    }
                    nums[i] = val;
                    break;
                }
            }
        }
        
        return nums[k - 1];         
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
