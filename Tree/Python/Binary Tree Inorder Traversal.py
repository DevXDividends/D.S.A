## TC:O(n) SC:O(h)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def fun(self, root, ans):
        if not root:
            return
        self.fun(root.left, ans)
        ans.append(root.val)
        self.fun(root.right, ans)

    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        ans = []
        self.fun(root, ans)
        return ans
