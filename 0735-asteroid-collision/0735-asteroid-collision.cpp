class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> s;
        vector<int> ans;
        int flag;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]<0){
                flag=0;
                while(s.size()>0 && abs(s.top())<=abs(asteroids[i])){
                    if(abs(s.top())==abs(asteroids[i])){
                        flag=1;
                         s.pop();
                        break;
                    }
                    s.pop();
                }
                if(s.size()==0 && flag==0) ans.push_back(asteroids[i]);
            }
            else{
                s.push(asteroids[i]);
            }
        }
        stack<int> curr;
        while(s.size()>0){
            curr.push(s.top());
            s.pop();
        }
        while(curr.size()>0){
            ans.push_back(curr.top());
            curr.pop();
        }
        
        return ans;
    }
};