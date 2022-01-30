class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        while k >= len(nums):
            k -= len(nums)
        
        if k == 0:
            return
        
        for i in range(len(nums) - k):
            nums.append(nums[0])
            del nums[0]
