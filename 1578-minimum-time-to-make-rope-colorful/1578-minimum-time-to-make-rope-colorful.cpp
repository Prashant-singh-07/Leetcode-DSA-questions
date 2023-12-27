class Solution {
public:
    int minCost(string colors, vector<int>& t) {
        int ans=0,temp,temp1;
        if(colors.size()<=1) return 0;
        temp = t[0];
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                temp1=temp;
                temp = min(temp,t[i+1]);
                ans+=temp;
                temp = temp1+t[i+1]-temp;
            }
            else temp=t[i+1];
        }
        return ans;
    }
};