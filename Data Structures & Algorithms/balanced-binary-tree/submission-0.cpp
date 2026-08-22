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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        unordered_map<TreeNode*,int> mp;
        mp[nullptr]=0;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if (node->left && mp.find(node->left)==mp.end()){
                stk.push(node->left);
            }
            else if (node->right && mp.find(node->right) == mp.end()){
                stk.push(node->right);

            }
            else{
                stk.pop();
                int lh = mp[node->left], rh = mp[node->right];
                if(abs(lh-rh)>1) return false;
                else mp[node] = 1+max(lh,rh);
            }
        }
        return true;
    }
};
