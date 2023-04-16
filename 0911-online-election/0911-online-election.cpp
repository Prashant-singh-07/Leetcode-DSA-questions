class TopVotedCandidate {
public:
    unordered_map<int,int> m;
    vector<int> time;
    vector<int> rank;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        int maxi=INT_MIN;
        int k;
        time=times;
        for(int i=0;i<times.size();i++){
               m[persons[i]]++;
            if(m[persons[i]]>=maxi){
                maxi=m[persons[i]];
                rank.push_back(persons[i]);
                k=persons[i];
            }
            else{
                rank.push_back(k);
            }
            
        }
    }
    
    int q(int t) {
        // //cout<<t<<endl;
        // int i=0;
        // for(i=0;i<time.size();i++){
        //     if(time[i]>=t){
        //         break;
        //     }
        // }
        // //cout<<t<<" "<<i<<endl;
        // if(i<time.size() && time[i]==t) return rank[i];
        // //cout<<"yha aaya kya"<<endl;
        // return rank[i-1];
        int index = lower_bound(time.begin(),time.end(),t) - time.begin();
        if(index==time.size()) return rank[index-1];
        
        if(time[index]==t){
            while(index<time.size() && time[index]==t) index++;
        }
        return rank[index-1];
        
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */