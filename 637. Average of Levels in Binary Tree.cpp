//https://leetcode.com/problems/average-of-levels-in-binary-tree/
//637. Average of Levels in Binary Tree


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
    void helper(TreeNode*root,long long int &sum,long long int &count,int k){
        if(root==NULL) return;
        if(k==0) {
            sum+=root->val; count++;
            return;
        }
        helper(root->left,sum,count,k-1);
        helper(root->right,sum,count,k-1);
    }
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int h=height(root);
        vector<double> ans;
        for(int i=0;i<h;i++){
            long long int sum, count; sum=count=0;
            helper(root,sum,count,i);
            ans.push_back(double(sum)/count);
        }
        return ans;
    }
};
