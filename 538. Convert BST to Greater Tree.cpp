//https://leetcode.com/problems/convert-bst-to-greater-tree/
//538. Convert BST to Greater Tree


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
    void helper(TreeNode*root,int& k){
        if(root==NULL) return;
        helper(root->right,k);
        k+=root->val;
        root->val=k;
        helper(root->left,k);
    }
    TreeNode* convertBST(TreeNode* root) {
        int k=0;
        helper(root,k);
        return root;
    }
};
