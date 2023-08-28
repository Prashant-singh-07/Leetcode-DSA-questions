class MyStack {
public:
    queue<int> q1,q2;
    MyStack() {
        int k=0;
    }
    
    void push(int x) {
        if(q1.size()>0)
        q1.push(x);
        else
            q2.push(x);
    }
    
    int pop() {
        int ans;
        if(q1.size()>0){
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            ans=q1.front();
            q1.pop();
        }
        else{
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            ans=q2.front();
            q2.pop();
        }
        return ans;
    }
    
    int top() {
        int ans;
        if(q1.size()>0){
            while(q1.size()!=1){
                q2.push(q1.front());
                q1.pop();
            }
            ans=q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else{
            while(q2.size()!=1){
                q1.push(q2.front());
                q2.pop();
            }
            ans=q2.front();
             q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    bool empty() {
        if(q1.size()==0 && q2.size()==0) return true;
        return false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */