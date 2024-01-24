// https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/

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
    int arr[10]={0};
    int ans;
    void check(){
        int count=0;
        for(int i=1;i<10;i++){
            if(arr[i]%2==1)
                ++count;
        }
        if(count<=1)
            ++ans;
    }
    int solve(TreeNode *root){
        if(!root->left and !root->right)
        {
            ++arr[root->val];
            check();
            return root->val;
        }
        ++arr[root->val];
        if(root->left){
            int op1=solve(root->left);
            --arr[op1];
        }
        if(root->right){
            int op2=solve(root->right);
            --arr[op2];
        }
        return root->val;

    }
    int pseudoPalindromicPaths (TreeNode* root) {
        if(root==nullptr)
            return 0;
        solve(root);
        return ans;
    }
};
