/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* temp = head;
        if(!temp) return temp;
            int i=0;
        unordered_map<Node*,int> m;
        vector<Node*> v;
        vector<Node*> dp;
        while(temp!=NULL){
            m[temp]=i;
            dp.push_back(temp);
            v.push_back(new Node(temp->val));
            cout<<temp->val<<" ";
            temp=temp->next;
        
            i++;
        }
        for(int j=0;j<i;j++){
           if(j+1<i) v[j]->next=v[j+1];
            
             if(dp[j]->random!=NULL)
            v[j]->random = v[m[dp[j]->random]];
            
//             if(dp[j]->random!=NULL){
//             if(v[m[dp[j]->random]]==NULL) v[m[dp[j]->random]] = new Node(dp[j]->random->val);
//                 v[j]->random= v[m[dp[j]->random]];
//             }
            
            
//            if(dp[j]->next!=NULL) {
//             if(v[m[dp[j]->next]]==NULL) v[m[dp[j]->next]] = new Node(dp[j]->next->val);
//                 v[j]->next= v[m[dp[j]->next]];
//             } 
            
        }
        return v[0];
        return head;
    }
};