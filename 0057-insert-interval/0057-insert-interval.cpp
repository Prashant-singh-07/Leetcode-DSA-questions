class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& naya) {
        
        vector<vector<int>> ans;
        int i=0,k,last;
        int n = intervals.size();
        int flag=0;
        while(i<intervals.size()){
            //ist condition:- it is previous element than our actual element
            if(intervals[i][1]<naya[0]) ans.push_back(intervals[i]);
            //Now coming on 2nd situation:-
            else if(intervals[i][1]>=naya[0]){
                if(intervals[i][0]>naya[1]) ans.push_back(naya);
                else{
                    k=min(naya[0],intervals[i][0]);
                    while(i<intervals.size() && intervals[i][0]<naya[1]){   
                        i++;
                    }
                    if(i==intervals.size()){
                        last = max(intervals[n-1][1],naya[1]);
                    }
                    else if(intervals[i][0]==naya[1]){
                        last=intervals[i][1];
                        i++;
                    }
                    else{
                     last = max(intervals[i-1][1],naya[1]);
                        //i--;
                    }
                    ans.push_back({k,last});
                }
                flag=1;
                break;
            }
           
            i++;
        }
        if(flag==0) ans.push_back(naya);
        
        while(i<intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
        
    }
};