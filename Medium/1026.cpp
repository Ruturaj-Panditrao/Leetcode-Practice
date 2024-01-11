// https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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

int traverse(TreeNode* root,int mx,int mn){
    if(root==NULL){
        return mx-mn;
    }
    int mxl=max(root->val,mx),mxr=max(root->val,mx);
    int mnl=min(root->val,mn),mnr=min(root->val,mn);
    return max(traverse(root->left,mxl,mnl),traverse(root->right,mxr,mnr));
}
    int maxAncestorDiff(TreeNode* root) {
        return traverse(root,INT_MIN,INT_MAX);
    }
};
