class Solution {
public:
    unordered_map<int,vector<int>> red,blue;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        for(int i=0;i<redEdges.size();i++){
            red[redEdges[i][0]].push_back(redEdges[i][1]);
        }
        for(int i=0;i<blueEdges.size();i++){
            blue[blueEdges[i][0]].push_back(blueEdges[i][1]);
        }
        vector<vector<int>> vis1(n,vector<int>(2,-1));
        vector<vector<int>> vis2(n,vector<int>(2,-1));
        vector<int> ans(n,-1);
        //first loop start with red;
        ans[0]=0;
        queue<int> q;
        q.push(0);
        int step=0,p,k;
       int flag=0;
        while(!q.empty()){
            k = q.size();
            while(k>0){
                p = q.front();
                q.pop();
                if(ans[p]==-1)
                ans[p]=step;
               
                    if(flag%2==0){
                        for(int i=0;i<red[p].size();i++){
                            if(vis1[red[p][i]][0]==-1) q.push(red[p][i]),vis1[red[p][i]][0]++;
                        }
                    }
                    else{
                        for(int i=0;i<blue[p].size();i++){
                           if(vis1[blue[p][i]][1]==-1) q.push(blue[p][i]),vis1[blue[p][i]][1]++;
                        }
                    
                }
                k--;
            }
            step++;
            flag++;
        }
        step=0;
        flag=1;
        queue<int> qu;
        qu.push(0);
        vector<int> leftu(n,-1);
        //Now chance for blue.
        while(!qu.empty()){
            k = qu.size();
            while(k>0){
                p = qu.front();
                qu.pop();
                if(leftu[p]==-1)
                leftu[p]=step;
                
                    if(flag%2==0){
                        for(int i=0;i<red[p].size();i++){
                            if(vis2[red[p][i]][0]==-1) qu.push(red[p][i]),vis2[red[p][i]][0]++;
                        }
                    }
                    else{
                        for(int i=0;i<blue[p].size();i++){
                            if(vis2[blue[p][i]][1]==-1) qu.push(blue[p][i]),vis2[blue[p][i]][1]++;
                        }
                    }
                
                k--;
            }
            step++;
            flag++;
        }
        
      for(int i=0;i<n;i++){
          //cout<<ans[i]<<" "<<leftu[i]<<endl;
          if(ans[i]!=-1 && leftu[i]!=-1) ans[i]=min(ans[i],leftu[i]);
          else if(ans[i]==-1) ans[i]=leftu[i];
          
      }
        return ans;
    }
};