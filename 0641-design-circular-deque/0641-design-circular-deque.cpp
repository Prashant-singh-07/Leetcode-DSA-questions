class MyCircularDeque {
public:
    class node{
        public:
        int val;
         node* next;
        node(int value){
            this->val=value;
            this->next=NULL;
        }
    };
    
    node* head=NULL;
    int count=0;
    int k;
    MyCircularDeque(int ka) {
        k=ka;
    }
    
    bool insertFront(int value) {
        if(count==k) return false;
        if(count==0){
            head = new node(value);
            count++;
            return true;
        }
        node* temp=new node(value);
        temp->next=head;
        head=temp;
        count++;
        return true;
    }
    
    bool insertLast(int value) {
        node* temp = head;
        if(count==k) return false;
        if(count==0){
            count++;
            head = new node(value);
            return true;
        }
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next = new node(value);
        count++;
        return true;
    }
    
    bool deleteFront() {
        if(count==0) return false;
        head=head->next;
        count--;
        return true;
    }
    
    bool deleteLast() {
        if(count==0) return false;
        if(count==1) head=NULL;
        else{
            node* temp=head;
            while(temp->next->next!=NULL) temp=temp->next;
            temp->next=NULL;
        }
        count--;
        return true;
    }
    
    int getFront() {
        if(count==0) return -1;
        return head->val;
    }
    
    int getRear() {
        if(count==0) return -1;
        node* temp=head;
        while(temp->next!= NULL) temp=temp->next;
        return temp->val;
    }
    
    bool isEmpty() {
        if(count==0) return true;
        return false;
    }
    
    bool isFull() {
        if(count==k) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */