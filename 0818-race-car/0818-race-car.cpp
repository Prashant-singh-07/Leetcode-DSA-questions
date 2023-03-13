class Solution {
public:
    int racecar(int target) {
        int pos,speed;
        queue<pair<int,int>> q;
        q.push({0,1});
        int n;
        pair<int,int> p;
        int step=0;
        while(!q.empty()){
            n = q.size();
            while(n>0){
                p=q.front();
                q.pop();
                pos=p.first;
                speed=p.second;
                if(pos==target) return step;
                //acceleration
                if(pos+speed<=10000 && pos+speed>0)
                q.push({pos+speed,speed*2});
                //reverse
                if(speed>0 && speed+pos>target){
                    q.push({pos,-1});
                }
                if(speed<0 && speed+pos<target){
                    q.push({pos,1});
                }
                n--;
            }
            step++;
        }
        return step;
    }
};