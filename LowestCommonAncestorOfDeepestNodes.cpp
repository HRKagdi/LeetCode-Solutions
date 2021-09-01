//https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/
//1123. Lowest Common Ancestor of Deepest Leaves

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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        return 1+max(height(root->left),height(root->right));
    }
    int depth(TreeNode* root,int x){
        if (root == NULL)
             return -1;
        int dist = -1;

        if ((root->val == x)

            || (dist = depth(root->left, x)) >= 0
 
            || (dist = depth(root->right, x)) >= 0)
 
            return dist + 1;
 
        return dist;
        
    }
    void Inorder(TreeNode* root,TreeNode* child,vector<TreeNode*> &v,int h){
        if(child==NULL) return;
        Inorder(root,child->left,v,h);
        if(depth(root,child->val)==h) v.push_back(child);
        Inorder(root,child->right,v,h);
    }
    bool search(TreeNode* root,int x){
        if(root==NULL) return false;
        if(root->val==x) return true;
        return search(root->left,x) || search(root->right,x);
    }
    TreeNode * helper(TreeNode * root,vector<TreeNode*> & v){
        if(root==NULL) return NULL;
        TreeNode * t1=helper(root->left,v);
        if(t1!=NULL) return t1;
        TreeNode * t2=helper(root->right,v);
        if(t2!=NULL) return t2;
        bool b=true;
        for(int i=0;i<v.size();i++){
            bool temp=search(root,v[i]->val);
            b=b&& temp;
        }
        if(b) return root;
        return NULL;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int h=height(root)-1; vector<TreeNode *> v;
        Inorder(root,root,v,h); 
        //for(int i=0;i<v.size();i++) cout<<v[i]->val<<" ";
        return helper(root,v);
    }
};
