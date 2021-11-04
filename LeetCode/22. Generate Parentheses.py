def recursiveGP(left, right, output, pt):
    if left > 0:
        newPt = pt + "("
        recursiveGP(left - 1, right, output, newPt);
    if right > 0 and left < right:
        newPt = pt + ")"
        recursiveGP(left, right - 1, output, newPt); 
    if left == 0 and right == 0:
        output.append(pt)
    
    
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        output = []
        left = right = n
        pt = ""
        
        recursiveGP(left, right, output, pt)
        
        return output
