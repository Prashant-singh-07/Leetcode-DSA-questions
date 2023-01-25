class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> left(n+1);
        int step=0;
        left[node1]=0;
        int k = edges[node1];
        step++;
        while(k!=-1){
            left[k]=step;
            step++;
            k=edges[k];
            if(k==node1 || (k!=-1 && left[k]>0)) break;
        }
        k = node2;
        step=0;
        int ans=INT_MAX;
        int asli=INT_MAX,p;
        vector<bool> vis(n);
        //for(int i=0;i<=n;i++) cout<<left[i]<<" ";
        while(k!=-1){
            if(k==node1 || (k!=-1 && left[k]>0)){
                p = max(step,left[k]);
                if(p<ans){
                    ans=p;
                    asli=k;
                }
                else{
                    if(p==ans) asli=min(asli,k);
                }
                
                
            }
           
            //cout<<endl<<step<<"  "<<k;
              step++;
            vis[k]=true;
            k=edges[k];
            if(k!=-1 && vis[k]) break;
            
               
        }
        if(ans==INT_MAX) return -1;
        return asli;
    }
};