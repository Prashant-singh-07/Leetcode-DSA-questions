class LRUCache {
public:
    class ListNode{
        public:
        int val;
        int key;
        ListNode* next;
        ListNode* prev;
        ListNode(int k,int value){
            this->val = value;
            this->key =k;
            this->next = NULL;
            this->prev=NULL;
        }
    };
    unordered_map<int,ListNode*> m;
    int total;
    ListNode* start=NULL;
    ListNode* end=NULL;
    
    LRUCache(int capacity) {
        total = capacity;
    }
    
    int get(int key) {
        if(m.find(key)==m.end()) return -1;
        int value = m[key]->val;
            if(m[key]->prev!=NULL){
                if(m[key]->next!=NULL) (m[key]->next)->prev = m[key]->prev;
                else end=m[key]->prev;
               (m[key]->prev)->next = m[key]->next;
            }
            else{
                start=m[key]->next;
                if(start!=NULL) start->prev=NULL;
            }
        if(start==NULL || start->next==NULL) end=start;
        // }
        
        
         ListNode* temp = new ListNode(key,value);
        if(end!=NULL){
            
                  end->next=temp;
                 temp->prev=end;
                 end=end->next;
        }
        else{
            start=temp;
            end=temp;
        }
          m[key]=temp;
        // ListNode* tempa=start;
        // while(tempa!=NULL){
        //     cout<<tempa->val<<"  ";
        //     tempa=tempa->next;
        // }
        // cout<<endl;
        return m[key]->val;
    }
    
    void put(int key, int value) {
         if(m.find(key)==m.end()){
             if(total>0){
                 ListNode* temp = new ListNode(key,value);
                 if(start==NULL){
                     start=temp;
                     end=start;
                 }
                 else{
                     end->next=temp;
                     temp->prev=end;
                     end=end->next;
                 }
                 total--;
                  m[key]=temp;
             }
             else{
                 m.erase(start->key);
                 start=start->next;
                 if(start!=NULL)
                 start->prev=NULL;
                 
                if(start==NULL || start->next==NULL ) end=start;
                 
                 ListNode* temp = new ListNode(key,value);
                 if(end!=NULL){
                  end->next=temp;
                 temp->prev=end;
                 end=end->next;
                 }
                 else{
            start=temp;
            end=temp;
        }
                  m[key]=temp;
             }
             
         }
        else{
           if(m[key]->prev!=NULL){
                if(m[key]->next!=NULL) (m[key]->next)->prev = (m[key]->prev);
               else end=m[key]->prev;
            (m[key]->prev)->next = m[key]->next;
            }
            else{
                start=m[key]->next;
                if(start!=NULL) start->prev=NULL;
            }
        // }
              if(start==NULL || start->next==NULL) end=start;
            
             ListNode* temp = new ListNode(key,value);
            if(end!=NULL){
                  end->next=temp;
                 temp->prev=end;
                 end=end->next;
            }
            else{
            start=temp;
            end=temp;
        }
            m[key]=temp;
        }
        return ;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */