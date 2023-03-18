class BrowserHistory {
public:
    int count=0;
    int flag=0;
    unordered_map<int,string> m;
    BrowserHistory(string homepage) {
        m[count]=homepage;
        flag=count;
        count++;
        return ;
    }
    
    void visit(string url) {
        
       for(int j=flag+1;j<count;j++){
         m.erase(j);
      }
        m[flag+1]=url;
            count = m.size();
            flag=count-1;
            return ;
            
        
        
         
        
        
    }
    
    string back(int steps) {
        if(flag-steps<0){
            flag=0;
            return m[0];
        }
        flag=flag-steps;
        return m[flag];
    }
    
    string forward(int steps) {
        if(flag+steps>=count){
            flag=count-1;
            return m[count-1];
        }
        flag=flag+steps;
        return m[flag];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */