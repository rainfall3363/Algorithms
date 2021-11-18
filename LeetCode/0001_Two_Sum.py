class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numDic = {}
        for i in range(len(nums)):
            if target - nums[i] in numDic:
                return [i, numDic.get(target - nums[i])] 
            numDic[nums[i]] = i
