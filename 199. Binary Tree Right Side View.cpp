//https://leetcode.com/problems/binary-tree-right-side-view/
//199. Binary Tree Right Side View

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
    void helper(TreeNode*root,int &ans,int k){
        if(root==NULL) return;
        if(k==0){
            ans=root->val;
            return;
        }
        helper(root->left,ans,k-1);
        helper(root->right,ans,k-1);
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int h=height(root);
        vector<int> ans;
        for(int i=0;i<h;i++){
            int temp;
            helper(root,temp,i);
            ans.push_back(temp);
        }
        return ans;
    }
};
