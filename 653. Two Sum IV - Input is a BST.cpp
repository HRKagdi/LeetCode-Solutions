//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
//653. Two Sum IV - Input is a BST

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
    int helper(TreeNode*root,int k){
        if(root==NULL) return 100000;
        if(root->val==k) return root->val;
        if(root->val>k){return helper(root->left,k);}
        else return helper(root->right,k);
    }
    void preorder(TreeNode*root,TreeNode*temp,int k,bool&b){
        if(root==NULL) return;
        int x=helper(temp,k-root->val);
        if(x!=root->val && x+root->val==k){
            b=true;
            return;
        }
        preorder(root->left,temp,k,b);
        preorder(root->right,temp,k,b);
    }

    bool findTarget(TreeNode* root, int k) {
        bool b=false;
        preorder(root,root,k,b);
        return b;
    }
};
