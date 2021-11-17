class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        output = []
        
        freq = {}
        for i in nums:
            if i in freq:
                freq[i] += 1
            else:
                freq[i] = 1
        
        output = sorted(freq, key = lambda x : freq[x], reverse = True)
        '''
        for key in freq.keys():
            output.append(key)
         '''
        return output[:k]
