class Solution {
public:
    /*
		Approach: 1
        Solving the problem using two pointers: previous and current.
        Time: 28 ms
	 */
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr) return head;
        while(head!=nullptr && head->val==val){
            head = head->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        while(curr!=nullptr){
            if(curr->val==val){
                prev->next = curr->next;
                curr = curr->next;
            }
            else{
                prev = curr;
                curr = curr->next;        
            }
        }
        return head;
    }
    
    /*
		Approach: 2
        Solving the problem using a single pointer: current.
        Time: 20 ms
    */
    
};