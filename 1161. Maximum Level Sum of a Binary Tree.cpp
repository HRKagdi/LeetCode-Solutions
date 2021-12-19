//https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
//1161. Maximum Level Sum of a Binary Tree

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
    void helper(TreeNode* root,int k,vector<int>&v){
        if(root==NULL) return;
        if(k<0) return;
        v[k]+=root->val;
        helper(root->left,k-1,v);
        helper(root->right,k-1,v);
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int maxLevelSum(TreeNode* root) {
        int h=height(root);
        vector<int> v(h+1,0);
        helper(root,h,v);
        reverse(v.begin(),v.end());
        int ans, maxi; maxi=INT_MIN;
        for(int i=0;i<v.size();i++){
            if(v[i]>maxi && v[i]!=0){
                maxi=v[i]; ans=i;
            }
        }
        return ans+1;
    }
};
