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
    bool isChild(TreeNode*root, TreeNode*child){

        stack<TreeNode*> stk;
        set<TreeNode*> mp;
        mp.insert(nullptr);
        stk.push(root);
        while(!stk.empty()){
            TreeNode*node = stk.top();

            if (node->left && mp.find(node->left)== mp.end())stk.push(node->left);
            else if(node->right && mp.find(node->right)==mp.end()) stk.push(node->right);
            else{
                stk.pop();
                if(node==child){ return true;}
                mp.insert(node);
            }
        }
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(isChild(p,q)) return p;
        if(isChild(q,p)) return q;
        unordered_map<TreeNode*,tuple<bool,bool>> mp;
        mp[nullptr] = {false,false};
        mp[p] = {true,false};
        mp[q] = {false,true};
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(node->left && mp.find(node->left)==mp.end()) stk.push(node->left);
            else if(node->right && mp.find(node->right)==mp.end()) stk.push(node->right);
            else{
                stk.pop();
                auto[lpParent,lqParent] = mp[node->left];
                auto[rpParent, rqParent] = mp[node->right];
                if((lpParent && rqParent)||(lqParent && rpParent)) return node;
                else{
                    mp[node] = {lpParent ||rpParent , lqParent || rqParent};
                }
            }
        }
        return root;
    }
};
