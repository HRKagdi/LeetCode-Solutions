//https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/submissions/
//1038. Binary Search Tree to Greater Sum Tree

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
    void Inorder(TreeNode * root,vector<int>& v){
        if(root==NULL) return ;
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
    }
    void helper(TreeNode * root,vector<TreeNode *>&v){
        if(root==NULL) return ;
        helper(root->left,v);
        v.push_back(root);
        helper(root->right,v);
    }
    TreeNode* bstToGst(TreeNode* root) {
        vector<int> v; Inorder(root,v);
        int l=v.size();
        for(int i=l-2;i>=0;i--){
            v[i]+=v[i+1];
        }
        vector<TreeNode *> tree;
        helper(root,tree);
        for(int i=0;i<l;i++){
            tree[i]->val=v[i];
        }
        return root;
        
    }
};
