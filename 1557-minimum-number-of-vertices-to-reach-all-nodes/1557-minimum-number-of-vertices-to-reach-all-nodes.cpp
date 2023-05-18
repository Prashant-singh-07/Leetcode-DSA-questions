class Solution {
public:
    int findUPar(int node, vector<int> &parent){     //function to find ultimate parent of the node
        if(node==parent[node]) return node;

        return parent[node] = findUPar(parent[node], parent);
    }
    
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        vector<int> parent(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<m;i++){
            int ult_u = findUPar(edges[i][0], parent);
            int ult_v = findUPar(edges[i][1], parent);

            if(parent[edges[i][1]]==edges[i][1]) parent[edges[i][1]] = ult_u; 
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(parent[i]==i) ans.push_back(i);
        }
        return ans;
        
    }
};;