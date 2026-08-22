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
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map<TreeNode*, pair<int,int>> mp;
        mp[nullptr] = {0,0};
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode*node = stk.top();
            if(node->left && mp.find(node->left)==mp.end()){
                stk.push(node->left);
            }
            else if(node->right && mp.find(node->right)== mp.end()){
                stk.push(node->right);
            }
            else{
                stk.pop();
                auto[lheight,ldia] = mp[node->left];
                auto[rheight,rdia] = mp[node->right];
                int h = 1+max(lheight, rheight);
                int d = max(lheight+rheight, max(ldia, rdia));
                mp[node] = {h,d};
            }
            
            


        }
        return mp[root].second;
    }
};
