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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p||!q) return p==q;
        stack<pair<TreeNode*,TreeNode*>> stk;
        stk.push(make_pair(p,q));
        while(!stk.empty()){
            auto[n1,n2] = stk.top();
            if(!n1||!n2){if(n1!=n2) return false;else stk.pop();}
            else if(n1->val!=n2->val) return false;
            else{
                stk.pop();
                stk.push(make_pair(n1->left,n2->left));
                stk.push(make_pair(n1->right,n2->right));
            }
        }
        return true;
    }
};
