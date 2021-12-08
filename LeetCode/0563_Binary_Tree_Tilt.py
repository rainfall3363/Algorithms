# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        answer = [0]
        findSubTreeTilt(root, answer)
        return answer[0]
    
def findSubTreeTilt(node, answer):
    if node == None:
        return 0
    
    left = findSubTreeTilt(node.left, answer)
    right = findSubTreeTilt(node.right, answer)
        
    answer[0] += abs(left - right)    
    
    return left + right + node.val
