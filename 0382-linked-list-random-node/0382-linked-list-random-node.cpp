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
    ListNode* temp;
    ListNode* curr;
    int count=0,len;
    Solution(ListNode* head) {
        temp=head;
        while(head!= NULL){
            head=head->next;
            count++;
        }
    }
    
    int getRandom() {
        len = rand()%count;
        curr= temp;
        while(len>0){
            len--;
            curr=curr->next;
        }
        return curr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */