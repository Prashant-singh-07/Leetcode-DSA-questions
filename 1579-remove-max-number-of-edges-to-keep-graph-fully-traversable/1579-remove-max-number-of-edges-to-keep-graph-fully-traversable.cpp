class Unionfind{
    private:
    vector<int> parent;
    int differentCompo;
    public:
    Unionfind(int n){
        differentCompo=n;
        for(int i=0;i<=n;i++){
            parent.push_back(i);
        }
    }
    bool hunion(int a,int b){
        int pa = find(a);
        int pb = find(b);
        if(pa==pb) return false;
        
        parent[pa] = b;
        differentCompo--;
        return true;
        
    }
    
    int find(int a){
        if(a==parent[a]) return a;
        return parent[a] = find(parent[a]);
    }
    
    bool united(){
        return differentCompo == 1;
    }
    
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        sort(edges.begin(),edges.end(),[](vector<int> &l,vector<int> &r){return l[0]>r[0];});
            
            Unionfind alice(n),bob(n);
        int type,one,two;
        int edgesAdded = 0;
        for(int i=0;i<edges.size();i++){
            type=edges[i][0];
            one=edges[i][1];
            two = edges[i][2];
             switch(type){
                 case 3:
                     edgesAdded += (alice.hunion(one,two) | bob.hunion(one,two));
                     break;
                 case 2:
                     edgesAdded += bob.hunion(one,two);
                     break;
                 case 1:
                     edgesAdded += alice.hunion(one,two);
                     break;
             }
        }
        
        return (alice.united() && bob.united()) ? (edges.size()-edgesAdded) : -1 ;
    }
};