// class Solution {
// public:
//     int minJumps(vector<int>& arr) {
//         int n = arr.size();
        
//         unordered_map<int,vector<int>> m;
//         for(int i=0;i<arr.size();i++){
//             m[arr[i]].push_back(i);
//         }
//         vector<int> vis(n,INT_MAX);
//         queue<int> q;
//         q.push(0);
//         vis[0]=0;
//         int k,count=0;
//         int num,ind;
//         while(q.size()>0){
//             k = q.size();
//             while(k>0){
//                 ind = q.front();
//                 if(ind==n-1) return count;
//                 q.pop();
//                 if(ind+1<n && vis[ind+1]>count+1){
//                     if(ind+1==n-1) return count+1;
//                     q.push(ind+1);
//                     vis[ind+1]=count+1;
//                 }
//                  if(ind-1>=0 && vis[ind-1]>count+1){
    
//                     q.push(ind-1);
//                     vis[ind-1]=count+1;
//                 }
//                  if(m[arr[ind]].size()>1){
//                     for(int j=0;j<m[arr[ind]].size();j++){
//                         if(m[arr[ind]][j]==n-1) return count+1;
//                         if(vis[m[arr[ind]][j]]>count+1){
//                             vis[m[arr[ind]][j]]=count+1;
//                             q.push(m[arr[ind]][j]);
//                         }
//                     }
//                 }
//                 k--;
//             }
//             count++;
//         }
//         return vis[n-1];
//     }
// };
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> indicesOfValue;
        for (int i = 0; i < n; i++)
            indicesOfValue[arr[i]].push_back(i);
        vector<bool> visited(n); visited[0] = true;
        queue<int> q; q.push(0);
        int step = 0;
        while (!q.empty()) {
            for (int size = q.size(); size > 0; --size) {
                int i = q.front(); q.pop();
                if (i == n - 1) return step; // Reached to last index
                vector<int>& next = indicesOfValue[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear(); // avoid later lookup indicesOfValue arr[i]
            }
            step++;
        }
        return 0;
    }
};