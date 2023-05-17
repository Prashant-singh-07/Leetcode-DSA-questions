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
    int pairSum(ListNode* head) {
        ListNode* first = head;
        stack<int> st;
        ListNode* second = head;
        st.push(first->val);
        while(second->next!=NULL && second->next->next!=NULL){
            first=first->next;
            st.push(first->val);
            second = second->next->next;
        }
        int ans=INT_MIN;
        int k;
        first=first->next;
       while(!st.empty()){
           k = st.top();
           st.pop();
           ans = max(ans,k+first->val);
           first=first->next;
       }
        return ans;
    }
};