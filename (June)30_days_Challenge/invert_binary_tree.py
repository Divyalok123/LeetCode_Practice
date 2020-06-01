#invert a binary tree

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        if root == None:
            return root
        temp = self.invertTree(root.left)
        root.left = self.invertTree(root.right)
        root.right = temp
        return root