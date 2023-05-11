/**
 * Definition for singly-linked list.
 * function ListNode(val, next) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.next = (next===undefined ? null : next)
 * }
 */
/**
 * @param {ListNode} head
 * @return {ListNode}
 */
var deleteDuplicates = function(head) {
 //if(this.val == 0 || this.next == null) return head;
    if(head!=null){
    let prev=head;
        if(head.next!=null){
    let agla = head.next;
    while(agla!=null){
        if(agla.val==prev.val){
            prev.next=agla.next;
        }
        else{
        prev=prev.next;
        }
        agla=agla.next;
    }
    }
    }
    return head;
};