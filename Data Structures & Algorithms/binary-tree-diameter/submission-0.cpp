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
map<TreeNode*,int> m;
int maxD(TreeNode* root, int d){
        if(root == nullptr) return d-1;
        if(m.count(root)) return m.at(root);
        else{return max(maxD(root->left, d+1), maxD(root->right, d+1));}
    }
    int maxW(TreeNode* root, int w){
        if(root==nullptr|| (root->left == nullptr && root->right == nullptr)) return w;
        TreeNode* l = root->left, *r = root->right;
        if(!m.count(l)) m[l] = maxD(l,1);
        if(!m.count(r)) m[r] = maxD(r,1);
        int k = max(m[l]+m[r],w);
        return max(k,max(maxW(root->left,k),maxW(root->right,k)));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int r = maxW(root,0);
        for (auto i:m){
            if(i.first!=nullptr){
cout<<i.first->val<<" "<<i.second<<endl;
            }
            
        }
        return r;
    }
};
