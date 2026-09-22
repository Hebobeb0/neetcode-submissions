# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self, root, depth):
        if not root:
            return
        if len(self.res)-depth-1<0:
            self.res.append([])
        self.res[depth].append(root.val)

        if root.left:
            self.dfs(root.left,depth+1)
        if root.right:
            self.dfs(root.right,depth+1)

    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        self.res=[]
        self.dfs(root,0)
        return self.res