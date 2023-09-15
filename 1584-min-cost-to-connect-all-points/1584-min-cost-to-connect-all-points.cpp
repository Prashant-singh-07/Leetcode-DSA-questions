class Solution {
    vector<int> par;
    int find(int a){
        if(par[a]<0) return a;
        return par[a] = find(par[a]);
    }
    void unionn(int a,int b){
        par[a]=b;
        return ;
    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par = vector<int>(n,-1);
        int dist;
        vector<pair<int,pair<int,int>>> v;
        for(int i=0;i<points.size();i++){
            for(int j=i+1;j<points.size();j++){
                dist = abs(points[j][0]-points[i][0]);
                dist+=abs(points[j][1] -points[i][1]);
                v.push_back({dist,{i,j}});
            }
        }
        int a,b,sum=0;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            a = find(v[i].second.first);
            b = find(v[i].second.second);
            if(a!=b){
                sum+=v[i].first;
                unionn(a,b);
            }
        }
        return sum;
    }
};