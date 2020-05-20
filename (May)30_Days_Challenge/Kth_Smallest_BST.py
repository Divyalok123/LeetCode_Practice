# Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
# You may assume k is always valid, 1 ≤ k ≤ BST's total elements.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution(object):
    def __init__(self):
        self.k = 0
    def kthSmallest(self, root, k):
        if(root == None):
            return -1 
        leftval = self.kthSmallest(root.left, k)
        if(leftval != -1):
            return leftval
        self.k+=1
        if self.k == k: 
            return root.val
        return self.kthSmallest(root.right, k)