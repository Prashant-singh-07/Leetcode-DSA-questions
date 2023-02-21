class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<long long, int> m1,m2;
        long long sq,temp1,temp2;
        int ans=0;
        for(int i=0;i<nums1.size();i++){
            temp1=nums1[i];
            sq = temp1*temp1;
            m1[sq]++;
        }
        for(int i=0;i<nums2.size();i++){
            temp1=nums2[i];
            sq = temp1*temp1;
            m2[sq]++;
        }
        for(int i=0;i<nums1.size()-1;i++){
            for(int j=i+1;j<nums1.size();j++){
                temp1=nums1[i];
                temp2=nums1[j];
                sq = temp1*temp2;
                if(m2.find(sq)!=m2.end()){
                    ans+=m2[sq];
                }
            }
        }
        for(int i=0;i<nums2.size()-1;i++){
            for(int j=i+1;j<nums2.size();j++){
                temp1=nums2[i];
                temp2=nums2[j];
                sq = temp1*temp2;
                if(m1.find(sq)!=m1.end()){
                    ans+=m1[sq];
                }
            }
        }
        return ans;
    }
};