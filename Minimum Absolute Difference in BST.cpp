//https://leetcode.com/problems/minimum-absolute-difference-in-bst/
//Minimum Absolute Difference in BST

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
    void Inorder(TreeNode * root,vector<int>&v){
        if(root==NULL) return ;
        Inorder(root->left,v);
        v.push_back(root->val);
        Inorder(root->right,v);
        
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> v; Inorder(root,v); int ans=INT_MAX;
        for(int i=0;i<v.size()-1;i++){
            ans=min(ans,v[i+1]-v[i]);
        }
        return ans;
    }
};
