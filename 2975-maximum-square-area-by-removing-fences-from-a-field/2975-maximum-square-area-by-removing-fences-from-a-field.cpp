class Solution {
//     vector<int> vgaps;
//         vector<int> hgaps;
        
//         hf.push_back(m); hf.push_back(1); // including boundaries
//         vf.push_back(n); vf.push_back(1);
        
//         sort(vf.begin(),vf.end());
//         sort(hf.begin(),hf.end());
                
//         for(int i=0; i<vf.size()-1; ++i)
//             for(int j=i+1; j<vf.size(); ++j)            
//                 hgaps.push_back(vf[j] - vf[i]);
//                                                     //finding all possible gaps
//         for(int i=0; i<hf.size()-1; ++i)
//             for(int j=i+1; j<hf.size(); ++j)
//                 vgaps.push_back(hf[j] - hf[i]);
        
//         long long res = -1;
        
//         sort(vgaps.begin(), vgaps.end());
//         unordered_map<int,int> hm;
        
//         for(int i=0; i<hgaps.size(); ++i) // storing all horizontal gaps in a map
//             hm[hgaps[i]] = 1;
        
//         for(int i=vgaps.size()-1; i>=0; --i)
//         {
//             if(hm[vgaps[i]]  == 1)           // checking for common gaps using the map
//             {
//                 long long l = vgaps[i];
//                 res = l*l;
//                 res = res%1000000007;
//                 break;
//             }
//         }

//         return res;
public:
    int maximizeSquareArea(int m, int n, vector<int>& h, vector<int>& v) {
        h.push_back(m);
        h.push_back(1);
        v.push_back(n);
        v.push_back(1);
        sort(h.begin(),h.end());
        sort(v.begin(),v.end());
        unordered_map<int,int> diff;
        long long area=-1;
        long long ans=-1;
        long long temp;
        int mod = 1000000007;
        for(int i=0;i<v.size()-1;i++){
            for(int j=i+1;j<v.size();j++){
                temp = v[j]-v[i];
                diff[temp]=1;
            }
        }
        for(int i=0;i<h.size()-1;i++){
            for(int j=i+1;j<h.size();j++){
                 temp = h[j]-h[i];
            if(diff[temp]==1){
                if(temp>area) area=temp;
            }
            }
        }
        if(area==-1) return -1;
        area = (area*area)%mod;
        return area%mod;
    
        
    }
};