//https://leetcode.com/problems/deepest-leaves-sum/
//1302. Deepest Leaves Sum

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
    int helper(TreeNode* root, int k){
        if(root==NULL) return 0;
        if(k==0) return root->val;
        return helper(root->left,k-1)+ helper(root->right,k-1);
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    int deepestLeavesSum(TreeNode* root) {
        int h=height(root); 
        return helper(root,h-1);
    }
};
