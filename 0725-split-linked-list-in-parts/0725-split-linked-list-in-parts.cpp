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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int count=0;
        ListNode* temp=head;
        ListNode* p = head;
        while(p!= NULL) {
            count++;
            p=p->next;
        }
        int flag = count%k;
        int curr = count/k;
        vector<ListNode*> v;
        ListNode* tempu;
        ListNode* start=temp;
        int i=0;
        while(temp!= NULL){
            i++;
            if(i<curr) temp=temp->next;
            else if(curr==i && flag==0){
                tempu=temp->next;
                temp->next=NULL;
                v.push_back(start);
               temp=tempu;
            start=tempu;
                i=0;
            }
            else if(i==curr && flag>0) temp=temp->next;
            else if(curr+1==i && flag>0){
              
               tempu=temp->next;
                temp->next=NULL;
                
                v.push_back(start);
               temp=tempu;
            start=tempu;
                flag--;
                i=0;
            }
            
        }
        ListNode* l = NULL;
        while(v.size()<k){
            v.push_back(l);
        }
        return v;
    }
};