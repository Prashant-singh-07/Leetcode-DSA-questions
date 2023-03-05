class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        
        unordered_map<int,vector<int>> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]].push_back(i);
        }
        vector<bool> visited(n);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int k,count=0;
        int num,i;
        while(q.size()>0){
            k = q.size();
            while(k>0){
                i = q.front();
                if(i==n-1) return count;
                q.pop();
                // if(ind+1<n && vis[ind+1]==-1){
                //     q.push(ind+1);
                //     vis[ind+1]++;
                // }
                //  if(ind-1>0 && vis[ind-1]==-1){
                //     q.push(ind-1);
                //     vis[ind-1]++;
                // }
                //     for(int j=0;j=m[arr[ind]].size();j++){
                //         if(vis[m[arr[ind]][j]]==-1){
                //             vis[m[arr[ind]][j]]++;
                //             //if(m[arr[ind]][j]==n-1) return count+1;
                //             q.push(m[arr[ind]][j]);
                //         }
                // }
                 vector<int>& next = m[arr[i]];
                next.push_back(i - 1); next.push_back(i + 1);
                for (int j : next) {
                    if (j >= 0 && j < n && !visited[j]) {
                        visited[j] = true;
                        q.push(j);
                    }
                }
                next.clear();
                k--;
            }
            count++;
        }
        return 0;
    }
};
// class Solution {
// public:
//     int minJumps(vector<int>& arr) {
//         int n = arr.size();
//         unordered_map<int, vector<int>> indicesOfValue;
//         for (int i = 0; i < n; i++)
//             indicesOfValue[arr[i]].push_back(i);
//         vector<bool> visited(n); visited[0] = true;
//         queue<int> q; q.push(0);
//         int step = 0;
//         while (!q.empty()) {
//             for (int size = q.size(); size > 0; --size) {
//                 int i = q.front(); q.pop();
//                 if (i == n - 1) return step; // Reached to last index
//                 vector<int>& next = indicesOfValue[arr[i]];
//                 next.push_back(i - 1); next.push_back(i + 1);
//                 for (int j : next) {
//                     if (j >= 0 && j < n && !visited[j]) {
//                         visited[j] = true;
//                         q.push(j);
//                     }
//                 }
//                 next.clear(); // avoid later lookup indicesOfValue arr[i]
//             }
//             step++;
//         }
//         return 0;
//     }
// };