// https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int required = 0;
        // vector<vector<int>>nodes;
        while(!q.empty()){
            // vector<int>level;
            int curr = q.size();
            for(int i=0; i<curr;i++){
               
            TreeNode* temp = q.front();
             if(i==0) required = temp->val;
            q.pop();
            if(temp!=NULL){
                // level.push_back(temp->val);
            if(temp->left!=NULL)q.push(temp->left);
            if(temp->right!=NULL)q.push(temp->right);
            }
            }
            // nodes.push_back(level);
        }
        // for(int i =0; i<nodes.size();i++)
        // {
        //     for(int j=0; j<nodes[i].size();j++){
        //         cout<<nodes[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // return nodes[nodes.size()-1][0];
        return required;
    }
    
};
