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
public:
    int goodNodes(TreeNode* root) {
        unordered_map<TreeNode*, int> mp;
        mp[root] = root->val;
        int res = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(node->left && mp.find(node->left) == mp.end()){stk.push(node->left); mp[node->left] = max(node->left->val, mp[node]);}
            else if(node->right && mp.find(node->right) == mp.end()) {stk.push(node->right); mp[node->right] = max(node->right->val, mp[node]);}
            else{
                stk.pop();
                if(node->val >= mp[node]) {++res; cout<<node->val<<endl;}

            }
        }
        return res;
    }
};
