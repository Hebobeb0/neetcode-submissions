# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        res = root.val
        def fun(curr):
            nonlocal res
            if not curr:
                return 0
            left = max(0, fun(curr.left))
            right = max(0, fun(curr.right))
            res = max(res, curr.val + left + right)
            return curr.val + max(left, right)
        fun(root)
        return res
