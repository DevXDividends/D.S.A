# TC:O(h) SC:(1)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def searchBST(self, root: Optional[TreeNode], val: int) -> Optional[TreeNode]:
        if not root:return None
        while root and root.val !=val:
            if val<root.val:root=root.left
            else:root=root.right
        return root

        
