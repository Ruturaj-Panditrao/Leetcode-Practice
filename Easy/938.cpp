// https://leetcode.com/problems/range-sum-of-bst/

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
class Solution 
{
public:
    void dfs(TreeNode* node, int low, int high) 
{
        if(node != NULL) 
        {
            if(node->val >= low and node->val <= high) ans += node->val;
            if(node->left) dfs(node->left, low, high);
            if(node->right) dfs(node->right, low, high);
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) 
{
        int ans = 0;
        dfs(root, low, high);
        return ans;
    }
};

// Space Complexity : O(1)
// Time Complexity : O(N) Traverse the Entire Tree
