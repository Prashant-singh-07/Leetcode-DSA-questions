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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp=NULL;
        ListNode* tempu;
        while(l1!=NULL){
            tempu = new ListNode(l1->val);
                tempu->next=temp;
            temp=tempu;
            l1=l1->next;
        }
        ListNode* dusra=NULL;
        while(l2!=NULL){
             tempu = new ListNode(l2->val);
                tempu->next=dusra;
          dusra=tempu;
            l2=l2->next;
        }
        int sum,carry=0;
        ListNode* ans=NULL;
        while(temp!=NULL && dusra!=NULL){
            sum = temp->val + dusra->val;
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            tempu = new ListNode(sum);
            tempu->next = ans;
            ans=tempu;
            temp=temp->next;
            dusra=dusra->next;
        }
        while(temp!=NULL){
            sum = temp->val;
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            tempu = new ListNode(sum);
           tempu->next = ans;
            ans=tempu;
            temp=temp->next;
        }
        while(dusra!=NULL){
            sum = dusra->val;
            sum+=carry;
            carry = sum/10;
            sum = sum%10;
            tempu = new ListNode(sum);
            tempu->next = ans;
            ans=tempu;
            dusra=dusra->next;
        }
        if(carry>0){
            tempu = new ListNode(carry);
            tempu->next = ans;
            ans=tempu;
        }
        
        return ans;
        
        
    }
};