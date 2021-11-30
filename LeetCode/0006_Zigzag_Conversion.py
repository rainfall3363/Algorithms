class Solution:
    def convert(self, s: str, numRows: int) -> str:
        rows = [''] * numRows
        
        if numRows == 1:
            return s
        
        i = j = 0
        while i < len(s):
            while j < numRows:
                if i < len(s):
                    rows[j] += s[i]
                    i += 1
                else:
                    break
                j += 1
            
            j = numRows - 2
            while j > 0:
                if i < len(s):
                    rows[j] += s[i]
                    i += 1
                else:
                    break
                j -= 1 
                    
        return ''.join(rows)
