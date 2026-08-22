/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    int maxD(TreeNode* root, int d){
        if(root == nullptr) return d-1;
        return max(maxD(root->left, d+1), maxD(root->right, d+1));
    }
public:
    int maxDepth(TreeNode* root) {
        return maxD(root,1);
    }
};
