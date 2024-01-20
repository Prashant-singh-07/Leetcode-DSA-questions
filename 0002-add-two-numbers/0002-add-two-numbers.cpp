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
        ListNode* sum = NULL;
        int k,r=0,q=0,a,b;
        ListNode* root;
        while(l1!=NULL || l2!=NULL){
            if(l1!=NULL) a = l1->val;
            else a=0;
            if(l2!=NULL) b = l2->val;
            else b=0;
            k = a+b;
            k+=q;
            q = k/10;
            r = k%10;
            if(sum==NULL) sum = new ListNode(r),root=sum;
            else {
                sum->next = new ListNode(r);
                sum=sum->next;
            }
            if(l1!=NULL)
            l1=l1->next;
            if(l2!=NULL)
            l2=l2->next;
        }
        while(q>0){
            r = q%10;
            q = q/10;
            
          sum->next = new ListNode(r);
        sum=sum->next;
            
        }
        return root;
    }
};