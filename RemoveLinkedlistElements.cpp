//https://leetcode.com/problems/remove-linked-list-elements/
//203. Remove Linked List Elements

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
    void deleteval(ListNode* head,int val){
        if(head==NULL) return ;
        if(head->next!=NULL && head->next->val==val){
            ListNode* a=head->next;
            head->next=head->next->next;
            delete a;
            deleteval(head->next,val);
        }
        else if(head!=NULL) deleteval(head->next,val);       
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*temp=head;
        deleteval(temp,val);
        while(head!=NULL && head->val==val) head=head->next;
        temp=head;
        while(temp!=NULL && temp->next!=NULL){
            if(temp->next->val==val) temp->next=temp->next->next;
            else temp=temp->next;
        }
        return head;
    }
};
