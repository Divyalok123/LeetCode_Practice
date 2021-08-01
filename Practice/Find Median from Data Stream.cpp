/*
https://leetcode.com/problems/find-median-from-data-stream/
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <array>
using namespace std;

// using AVL Tree
class MedianFinder {
public:
    class TreeNode {
    public:
        TreeNode *left, *right;
        int val;
        int size;
        int height;
        
        TreeNode(): left(NULL), right(NULL), val(INT_MIN), size(1), height(1) {}
        TreeNode(int val): left(NULL), right(NULL), val(val), size(1), height(1) {}
    };
    
    int height(TreeNode* root) {
        return !root ? 0 : root->height;
    }
    
    int size(TreeNode* root) {
        return !root ? 0 : root->size;
    }
    
    TreeNode* leftrotate(TreeNode* root) {
        TreeNode* right = root->right;
        if(!right) return root;
        TreeNode* rleft = right->left;
        
        right->left = root;
        root->right = rleft;
        
        root->height = 1 + max(height(root->left), height(root->right));
        right->height = 1 + max(height(right->left), height(right->right));
        
        root->size = 1 + size(root->left) + size(root->right);
        right->size = 1 + size(right->left) + size(right->right);
        
        return right;
    }
    
    TreeNode* rightrotate(TreeNode* root) {
        TreeNode* left = root->left;
        if(!left) return root;
        TreeNode* lright = left->right;
        
        left->right = root;
        root->left = lright;
        
        root->height = 1 + max(height(root->left), height(root->right));
        left->height = 1 + max(height(left->left), height(left->right));
        
        root->size = 1 + size(root->left) + size(root->right);
        left->size = 1 + size(left->left) + size(left->right);
        
        return left;
    }
    
    TreeNode* addNode(TreeNode* root, int val) {
        if(!root) {
            root = new TreeNode(val);
            return root;
        }
        
        if(val < root->val)
            root->left = addNode(root->left, val);
        else 
            root->right = addNode(root->right, val);
        
        root->height = 1 + max(height(root->left), height(root->right));
        root->size++;
        
        int diff = height(root->left) - height(root->right);
        
        if(diff > 1) {
            
            if(val > root->left->val)
                root->left = leftrotate(root->left);
            return rightrotate(root);
            
        } else if(diff < -1) {
            
            if(val < root->right->val)
                root->right = rightrotate(root->right);
            return leftrotate(root);
        }
        
        return root;
    }
    
    int findval(TreeNode* root, int ind, int curr) {
        int leftsize = curr;
        if(root->left) leftsize += root->left->size;
        
        if(leftsize == ind) return root->val;
        
        if(leftsize < ind)
            return findval(root->right, ind, leftsize + 1);
        
        return findval(root->left, ind, curr);
    }
    
    TreeNode* avl;
    MedianFinder() {
        avl = NULL;
    }
    
    void addNum(int num) {
        avl = addNode(avl, num);
    }
    
    double findMedian() {
        int size = avl->size;
        
        if(size&1)
            return findval(avl, size/2, 0);
        
        double val1 = findval(avl, (size-1)/2, 0);
        double val2 = findval(avl, size/2, 0);
        
        return (val1 + val2)/2;
    }
};


// better solution using minheap and maxheap
class MedianFinder {
    priority_queue<double, vector<double>, greater<double>> minheap;
    priority_queue<double> maxheap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(double num) {
        int mins = minheap.size();
        int maxs = maxheap.size();
        
        if((mins & 1) != (maxs & 1)) {
            maxheap.push(num);
            if(maxheap.top() > minheap.top()) {
                minheap.push(maxheap.top());
                maxheap.pop();
                maxheap.push(minheap.top());
                minheap.pop();
            }
        } else {
            maxheap.push(num);
            minheap.push(maxheap.top());
            maxheap.pop();
        }
    }
    
    double findMedian() {
        int mins = minheap.size();
        int maxs = maxheap.size();
            
        if(mins == 0) return maxheap.top();
        
        if((mins & 1) != (maxs & 1))
            return mins > maxs ? minheap.top() : maxheap.top();
        
        return (minheap.top() + maxheap.top()) / 2l;
    }
};

// naive implementaion using minheap and maxheap
class MedianFinder {
    priority_queue<double, vector<double>, greater<double>> minheap;
    priority_queue<double> maxheap;
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    
    void addNum(double num) {
        double mins = minheap.size();
        double maxs = maxheap.size();
        
        if(mins > maxs) {
            if(minheap.top() < num) {
                // cout << "pushing " << minheap.top() << " to maxheap & ";
                maxheap.push(minheap.top());
                minheap.pop();
                // cout << "pushing " << num << " to minheap" << endl;
                minheap.push(num);
            } else {
                // cout << "pushing " << num << " to maxheap" << endl;
                maxheap.push(num);
            }
        } else if(mins < maxs) {
            if(maxheap.top() > num) {
                // cout << "pushing " << maxheap.top() << " to minheap & ";
                minheap.push(maxheap.top());
                maxheap.pop();
                // cout << "pushing " << num << " to maxheap" << endl;
                maxheap.push(num);
            } else {
                // cout << "pushing " << num << " to minheap" << endl;
                minheap.push(num);
            }
        } else {
            if(maxheap.size() == 0) {
                // cout << "pushing " << num << " to maxheap" << endl;
                maxheap.push(num); 
            } else if(num > minheap.top()) {
                // cout << "pushing " << minheap.top() << " to maxheap & ";
                maxheap.push(minheap.top());
                minheap.pop();
                // cout << "pushing " << num << " to minheap" << endl;
                minheap.push(num);
            } else if(num < maxheap.top()) {
                // cout << "pushing " << maxheap.top() << " to minheap & ";
                minheap.push(maxheap.top());
                maxheap.pop();
                // cout << "pushing " << num << " to maxheap" << endl;
                maxheap.push(num);
            } else {
                // cout << "pushing " << num << " to maxheap" << endl;
                maxheap.push(num);
            }
        }
    }
    
    double findMedian() {
        int mins = minheap.size();
        int maxs = maxheap.size();
            
        // cout << "mins: " << mins << " maxs: " << maxs << endl;
        
        if(mins == 0) return maxheap.top();
        if(maxs == 0) return minheap.top();
        
        if((mins & 1) != (maxs & 1))
            return mins > maxs ? minheap.top() : maxheap.top();
        
        return (minheap.top() + maxheap.top()) / 2l;
    }
};

