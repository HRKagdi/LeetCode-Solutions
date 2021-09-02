//https://leetcode.com/problems/add-two-numbers/
//2. Add Two Numbers

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
    int length(ListNode * l){
        ListNode * temp=l; int ans=0;
        while(temp!=NULL){
            temp=temp->next; ans++;
        }
        return ans;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int a=length(l1); int b=length(l2);
        if(a==1 && l1->val==0) return l2;
        if(b==1 && l2->val==0) return l1;
        if(a>b){
            int x=a-b; 
            ListNode * p=l2;
            while(p->next!=NULL) p=p->next;
            for(int i=1;i<=x;i++){
                ListNode *c=new ListNode(0);
                p->next=c; p=c;
            }
        }
        else{
            int x=b-a;
            ListNode * p=l1;
            while(p->next!=NULL) p=p->next;
            for(int i=1;i<=x;i++){
                 ListNode*c=new ListNode(0);
                p->next=c; p=c;
            }
        }
        ListNode * p=l1; ListNode * q=l2; 
        for(int i=1;i<=max(a,b);i++){
            int t=p->val+q->val+carry;  
            if(t<10){ p->val=t; carry=0;}
            else {
                int temp=t%10; t/=10;
                p->val=temp; carry=t;
            }
            p=p->next; q=q->next;
        }
        if(carry!=0){
            ListNode * temp=new ListNode(carry);
            p=l1; while(p->next!=NULL) p=p->next;
            p->next=temp;
        }
        return l1;
    }
};
