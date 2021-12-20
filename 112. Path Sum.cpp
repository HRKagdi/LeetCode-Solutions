//https://leetcode.com/problems/path-sum/
//112. Path Sum

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
    bool helper(TreeNode* root,int targetSum,int currSum){
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL && currSum+root->val==targetSum){
            return true;
        } 
        return helper(root->left,targetSum,currSum+root->val) || 
            helper(root->right,targetSum,currSum+root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int currSum=0;
        return helper(root,targetSum,currSum);
    }
};
