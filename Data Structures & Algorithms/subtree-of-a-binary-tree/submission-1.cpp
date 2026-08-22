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
    bool sameTree(TreeNode*t1,TreeNode*t2){
        stack<pair<TreeNode*,TreeNode*>>stk;
        stk.push(make_pair(t1,t2));
        while(!stk.empty()){
            auto[n1,n2]=stk.top();
            if(!n1&&!n2){stk.pop();continue;}
            else if(!n1||!n2)return false;
            else if(n1->val != n2->val) return false;
            else{
                stk.pop();
                stk.push(make_pair(n1->left,n2->left));
                stk.push(make_pair(n1->right,n2->right));
            }
        }
        return true;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> stk;
        stk.push(root);
        bool found = false;
        while(!stk.empty()){
            TreeNode*node = stk.top();
            stk.pop();
            if(!node) continue;
            stk.push(node->left);stk.push(node->right);
            if(node->val == subRoot->val && sameTree(node,subRoot)) return true;
        }
        return false;
    }
    
};
