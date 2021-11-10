class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        if len(arr) == 1:
            return 1

        output = turbulence = 1
        signs = ""
        
        for i in range(len(arr) - 1):
            if arr[i] > arr[i + 1]:
                signs += ">"
            elif arr[i] < arr[i + 1]:
                signs += "<"
            else:
                signs += "="
        
        if "<" not in signs and ">" not in signs:
            return 1
        elif len(signs) == 1:
            return 2
        
        for i in range(len(signs) - 1):
            if signs[i] != "=" and signs[i + 1] != "=" and signs[i] != signs[i + 1]:
                turbulence += 1
            else:
                turbulence = 1
            output = max(output, turbulence + 1)
                
        # < > 부호가 하나라도 있을때: 2
        # 부호가 하나도 없을때: 1
        
        return output
    
