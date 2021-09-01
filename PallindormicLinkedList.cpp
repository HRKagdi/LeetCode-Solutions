//https://leetcode.com/problems/palindrome-linked-list/
//234. Palindrome Linked List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void helper(ListNode* head,vector<int>& v){
        if(head==NULL) return;
        v.push_back(head->val);
        helper(head->next,v);
    }
    bool checkpallindrome(vector<int>&v,int l,int r){
        if(l>=r) return true;
        if(v[l]!=v[r]) return false;
        return checkpallindrome(v,l+1,r-1);
    }
    bool isPalindrome(ListNode* head) {
        vector<int> v;
        helper(head,v);
        return checkpallindrome(v,0,v.size()-1);
        
    }
};
