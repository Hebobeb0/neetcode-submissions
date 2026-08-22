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
    bool isValidBST(TreeNode* root) {
        //first find max and min numbers for each left and right subtree;
        unordered_map<TreeNode*, pair<int,int>> mp;
        //<min, max>
        mp[nullptr] = make_pair(10001,-10001);
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode* node = stk.top();
            if(node->left && mp.find(node->left) == mp.end()) stk.push(node->left);
            else if (node->right && mp.find(node->right)==mp.end())stk.push(node->right);
            else {
                stk.pop();
                mp[node] = make_pair(min(node->val,min(mp[node->left].first,mp[node->right].first)), max(node->val,max(mp[node->left].second,mp[node->right].second)));
            }
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int c = q.size();
            while(c){
                bool l,r;
                TreeNode* node = q.front();
                q.pop();
                --c;
                if(node->left){
                    q.push(node->left);
                    if(mp[node->left].second<node->val) l = true;
                    else l=false;
                }
                else{
                    l = true;
                }
                if(node->right){
                    q.push(node->right);
                    if(mp[node->right].first>node->val) r= true;
                    else r= false;
                }
                else r = true;
                if(!(l&&r)) return false;
            }
        }
        return true;
    }
};
