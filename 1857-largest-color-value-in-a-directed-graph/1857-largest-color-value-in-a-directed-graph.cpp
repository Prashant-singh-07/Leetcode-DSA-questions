// class Solution {
//     unordered_map<int,vector<int>> graph;
//     unordered_map<int,int> visited;
//     int n;
//     vector<vector<int>> res;
//     void fun(string& colors,int ind){
//         visited[ind]++;
//        res[ind][colors[ind]-'a']++;
//         for(int i=0;i<graph[ind].size();i++){
//             if(visited.find(graph[ind][i])==visited.end()){
//                 fun(colors,graph[ind][i]);
//             }
//             for(int j=0;j<26;j++){
//                 res[ind][j]+=res[graph[ind][i]][j];
//             }
//         }
//         return ;
//     }
// public:
//     int largestPathValue(string colors, vector<vector<int>>& edges) {
//        n = colors.size();
//         res = vector<vector<int>>(n+1,vector<int>(27,0));
//         for(int i=0;i<edges.size();i++){
//             graph[edges[i][0]].push_back(edges[i][1]);
//         }
        
//         // at starting only check that graph contains cycle or not.
//         // if it contain cycle then return -1;
//         detected cycle
        
//         for(auto k:graph){
//             if(visited.find(k.first)==visited.end()){
//                 fun(colors,k.first);
//             }
//         }
//         int ans=INT_MIN;
//         for(int i=0;i<res.size();i++){
//             for(int j=0;j<26;j++){
//                 ans=max(ans,res[i][j]);
//             }
//         }
//         return ans;
//     }
// };




class Solution {
    typedef array<int, 26> T;
public:
    int largestPathValue(string C, vector<vector<int>>& E) {
        unordered_map<int, vector<int>> G;
        vector<int> indegree(C.size());
        for (auto &e : E) {
            G[e[0]].push_back(e[1]); // build graph
            indegree[e[1]]++; // count indegrees
        }
        vector<T> cnt(C.size(), T{}); // cnt[i][j] is the maximum count of j-th color from the ancester nodes to node i.
        queue<int> q;
        for (int i = 0; i < C.size(); ++i) {
            if (indegree[i] == 0) { // if this node has 0 indegree, we can use it as a source node
                q.push(i);
                cnt[i][C[i] - 'a'] = 1; // the count of the current color should be 1
            }
        }
        int ans = 0, seen = 0;
        while (q.size()) {
            auto u = q.front();
            q.pop();
            int val = *max_element(begin(cnt[u]), end(cnt[u])); // we use the maximum of all the maximum color counts as the color value.
            ans = max(ans, val);
            ++seen;
            for (int v : G[u]) {
                for (int i = 0; i < 26; ++i) {
                    cnt[v][i] = max(cnt[v][i], cnt[u][i] + (i == C[v] - 'a')); // try to use node `u` to update all the color counts of node `v`.
                }
                if (--indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        return seen < C.size() ? -1 : ans;
    }
};