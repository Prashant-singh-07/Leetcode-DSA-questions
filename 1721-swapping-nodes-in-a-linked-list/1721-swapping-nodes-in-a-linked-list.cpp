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
    ListNode* swapNodes(ListNode* head, int k) {
        int count=0;
        if(!head || head->next==NULL) return head;
        ListNode* curr = head;
        ListNode* first;
        ListNode* prev;
        int temp;
        vector<ListNode*> v;
        while(curr!=NULL){
            count++;
            if(count==k){
                first=curr;
            }
            
            v.push_back(curr);
            curr=curr->next;
        }
        temp=v[count-k]->val;
       v[count-k]->val=first->val;
     first->val=temp;
     return head;
    }
};