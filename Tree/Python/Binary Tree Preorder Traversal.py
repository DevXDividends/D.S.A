// TC:O(n) SC:O(n)
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def traversal(self,root,ans):
        if not root:return 
        ans.append(root.val)
        self.traversal(root.left,ans)
        self.traversal(root.right,ans)
    def preorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.traversal(root,ans)
        return ans
        
