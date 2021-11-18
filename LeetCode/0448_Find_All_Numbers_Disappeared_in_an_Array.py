class Solution:
    def findDisappearedNumbers(self, nums: List[int]) -> List[int]:
        result = []
        ascendingNums = [0 for i in range(len(nums))]
        for i in range(len(nums)):
            ascendingNums[nums[i] - 1] = 1
        
        for i in range(len(nums)):
            if ascendingNums[i] == 0:
                result.append(i + 1)
        
        return result
