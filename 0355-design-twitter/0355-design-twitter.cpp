class Twitter {
public:
    //First of all whenever we r adding anything then try to include time also, which will keep track of recent activities.
// everyone will have their personal account,so try to access it using unique id:- i.e hash table
    vector<pair<int,int>> v;
    unordered_map<int,unordered_map<int,int>> m;
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        v.push_back({userId,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count=0;
        for(int i=v.size()-1;i>=0 && count<10;i--){
            if(v[i].first==userId || m[userId][v[i].first]>0){
                feed.push_back(v[i].second);
                count++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
          m[followerId][followeeId]++;
    }
    
    void unfollow(int followerId, int followeeId) {
        m[followerId][followeeId]=0;
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */