class Solution {
private:
    vector<int> color;
    vector<vector<int>> ed;
public:
    bool dfs(int cur, int ab){
        bool res = true;
        color[cur] = ab;
        for(auto i : ed[cur]){
            if(color[i] != -1){
                if(ab == color[i]) res = false;
                continue;
            }
            res &= dfs(i, ab^1);
        }
        return res;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<int> (n, -1);
        ed = graph;
        bool res = true;
        for(int i = 0; i<n; i++) if(color[i] == -1) res &= dfs(i, 0);
        return res;
    }
};