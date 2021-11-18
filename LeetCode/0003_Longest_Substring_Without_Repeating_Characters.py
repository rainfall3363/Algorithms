class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        idx = length = longestLength = 0
        alphabetDic = {}
        
        if len(s) == 1:
            return 1
        
        while idx < len(s):
            if s[idx] in alphabetDic:
                idx = alphabetDic[s[idx]] + 1
                longestLength = max(length, longestLength)
                length = 0
                alphabetDic.clear()
            else:
                alphabetDic[s[idx]] = idx
                length += 1
                idx += 1

        longestLength = max(length, longestLength)
        
        return longestLength
        
