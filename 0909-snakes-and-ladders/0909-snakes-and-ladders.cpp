class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
       //Problem statement
        int end = board.size();
        int j = end;
        end=end*end;
        int n,val,step=0,rem,qt,p;
        vector<bool> vis(end+1,false);
        queue<int> q;
        q.push(1);
        vis[1]=true;
        while(q.size()>0){
            n = q.size();
            while(n>0){
                val = q.front();
                q.pop();
                //if(vis[val]==false){
                if(val+6>=end) return step+1;
            for(int i=1;i<=6;i++){
                
                //Now try to find that value in matrix.
                rem = (val+i)%j;
                qt = (val+i)/j;
                if(rem==0) qt--;
                if(qt%2==0){
                    if(rem!=0)
                    p = board[j-1-qt][rem-1];
                    else
                    p = board[j-1-qt][j-1];
                    //vis[p]=true;
                // if(p==-1) q.push(val+i),vis[val+i]=true;
                // else q.push(p),vis[p]=true;
                
                }
                else{
                    if(rem!=0)
                    p = board[j-1-qt][j-rem];
                    else p = board[j-1-qt][0];
                }
                if(p==-1){
                    if(vis[val+i]==false){
                 q.push(val+i);
                    vis[val+i]=true;
                    }
                }
                else
                {
                    if(p==end) return step+1;
                    if(vis[p]==false)
                    q.push(p);
                    vis[p]=true;
                }
                
            }
            
                n--;
            }
            
            step++;
        }
        // cout<<"step kitna h ye bhi bta do "<<step<<endl;
        // cout<<"kya bhai koi nhi mila ?"<<endl;
        return -1;
    }
};