class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        map<int,vector<int>> m;
        int temp,count;
        for(int i=0;i<arr.size();i++){
            temp=arr[i];
            count=0;
            while(arr[i]>0){
                count += (arr[i]%2!=0?1:0);
                arr[i]=arr[i]/2;
            }
            m[count].push_back(temp);
        }
        int i=0;
        vector<int> k;
        for(auto p:m){
            k=p.second;
            sort(k.begin(),k.end());
            for(int j=0;j<k.size();j++) arr[i]=k[j],i++;
        }
        return arr;
    }
};