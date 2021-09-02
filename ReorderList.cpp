//https://leetcode.com/problems/reorder-list/
//143. Reorder List

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
    void reorderList(ListNode* head) {
        vector<int> v;
        ListNode* temp=head; int l=0;
        while(temp!=NULL){
            v.push_back(temp->val); temp=temp->next; l++;
        }
        ListNode * ans=new ListNode(v[0]);
        if(l==1) return ;
        ListNode * t=new ListNode(v[l-1]);
        ans->next=t;  ListNode * w=t; 
        for(int i=1;i<=l/2;i++){
            ListNode * t=new ListNode(v[i]);
            ListNode * u=new ListNode(v[l-i-1]);
            w->next=t; w=t; w->next=u; w=u;
        }
        w=ans; temp=head;
        while(temp!=NULL){
            temp->val=w->val;
            temp=temp->next; w=w->next;
        }
    }
};
