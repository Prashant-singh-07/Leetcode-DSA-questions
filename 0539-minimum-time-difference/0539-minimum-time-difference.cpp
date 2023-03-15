class Solution {
public:
    int findMinDifference(vector<string>& time) {
        sort(time.begin(),time.end());
        int ans=INT_MAX,count=0;
        int n = time.size();
        string s;
        int prevh,prevm,currh,currm;
        for(int i=0;i<n-1;i++){
            count=0;
            s = time[i].substr(0,2);
            
            prevh = stoi(s);
           s = time[i].substr(3,2);
            
            prevm = stoi(s);
            cout<<"yr bhi nhi chla";
            s = time[i+1].substr(0,2);
            currh = stoi(s);
            cout<<"yr bhi nhi chla";
            s = time[i+1].substr(3,2);
            currm = stoi(s);
            if(currh==prevh) count =  (currm-prevm);
            else{
                if(currm>=prevm){
                    count = (currh-prevh)*60;
                    count+= (currm-prevm);
                }
                else{
                    count = (currh-prevh-1)*60;
                    count+=(60-prevm);
                    count+=currm;
                }
            }
            ans = min(ans,count);
        }
        cout<<"ye chl gya ka";
        s = time[0].substr(0,2);
        prevh = stoi(s);
        s = time[0].substr(3,2);
            prevm = stoi(s);
        s = time[n-1].substr(0,2);
            currh = stoi(s);
        s = time[n-1].substr(3,2);
            currm = stoi(s);
        count = prevh*60;
        count+=prevm;
        count+= (60-currm);
        count+= (23-currh)*60;
        ans = min(ans,count);
        return ans;
    }
};