class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        ss = list(s)
        tt = list(t)
        ss.sort()
        tt.sort()
        
        for i in range(len(ss)):
            if ss[i] != tt[i]:
                return tt[i]
            
        return tt[-1]
