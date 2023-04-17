class Solution {
public:
    unordered_map<string,bool> vis;
    unordered_map<string,int> supply;
    unordered_map<string,int> r;
    unordered_map<string,int> st;
    bool check(int index,vector<string>& recipes,vector<vector<string>>& ing){
        if(vis.find(recipes[index])!=vis.end()) return vis[recipes[index]];
        st[recipes[index]]++;
        for(int i=0;i<ing[index].size();i++){
            if(supply.find(ing[index][i])!=supply.end()) continue;
            else if(r.find(ing[index][i])!=r.end()){
                if(st.find(ing[index][i])!=st.end()) return false;
                if(!check(r[ing[index][i]],recipes,ing)){
                    return vis[recipes[index]] = false;
                }
            }
            else{
                return vis[recipes[index]] =false;
            }
        }
        st.erase(recipes[index]);
        return vis[recipes[index]] = true;
        
    }
    
    
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        
        vector<string> ans;
        for(int i=0;i<supplies.size();i++){
            supply[supplies[i]]++;
        }
        for(int i=0;i<recipes.size();i++){
            r[recipes[i]]=i;
        }
        for(int i=0;i<recipes.size();i++){
            if(check(i,recipes,ingredients)){
                ans.push_back(recipes[i]);
            }
        }
        return ans;
        
        
        
        
    }
};