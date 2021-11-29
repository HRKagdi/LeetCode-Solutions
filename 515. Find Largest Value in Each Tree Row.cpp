//https://leetcode.com/problems/find-largest-value-in-each-tree-row/
//515. Find Largest Value in Each Tree Row

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
    void helper(TreeNode*root,int& maxi,int k){
        if(root==NULL) return ;
        if(k==0){
            maxi=max(maxi,root->val);
            return;
        }
        helper(root->left,maxi,k-1);
        helper(root->right,maxi,k-1);
    }
    int height(TreeNode*root){
        if(root==NULL) return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    vector<int> largestValues(TreeNode* root) {
        int h=height(root);
        vector<int> ans;
        for(int i=0;i<h;i++){
            int maxi=INT_MIN; helper(root,maxi,i);
            ans.push_back(maxi);
        }
        return ans;
    }
};
