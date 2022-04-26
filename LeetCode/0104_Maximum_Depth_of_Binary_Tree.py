# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root == None:
            return 0
        
        bigDepth = [1]
        digging(root, 1, bigDepth)
        return bigDepth[0]
        

def digging(node, presentDepth, bigDepth):
    if presentDepth > bigDepth[0]:
        bigDepth[0] = presentDepth
        
    if node.left != None:
        digging(node.left, presentDepth + 1, bigDepth)
    if node.right != None:
        digging(node.right, presentDepth + 1, bigDepth)
