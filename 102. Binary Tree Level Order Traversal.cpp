//https://leetcode.com/problems/binary-tree-level-order-traversal/
//102. Binary Tree Level Order Traversal


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
    void helper(TreeNode* root,vector<int>&v,int k){
        if(root==NULL) return;
        if(k==0){
            v.push_back(root->val);
            return;
        }
        helper(root->left,v,k-1);
        helper(root->right,v,k-1);
    }
    int height(TreeNode*root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int h=height(root);
        vector<vector<int>> ans;
        for(int i=0;i<h;i++){
            vector<int>temp;
            helper(root,temp,i);
            ans.push_back(temp);
        }
        return ans;
    }
};
