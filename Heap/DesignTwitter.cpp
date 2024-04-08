class Twitter {
private:
    priority_queue<vector<int>> pq;
    unordered_map<int, map<int, int>> followers;
    int postNum;

public:
    Twitter() {
        postNum = 1;
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({postNum, tweetId, userId});
        postNum++;
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> resultFeed;
        vector<vector<int>> temp;
        int feedCount = 10;

        while(!pq.empty() && feedCount > 0){
            vector<int> p = pq.top();
            temp.push_back(p);
            pq.pop();

            int tweet = p[1];
            int user = p[2];

            if(user == userId || followers[user].find(userId) != followers[user].end()){
                resultFeed.push_back(tweet);
                feedCount--;
            }
        }

        for(int i = temp.size()-1; i >= 0; i--){
            pq.push(temp[i]);
        }

        return resultFeed;
        
    }
    
    void follow(int followerId, int followeeId) {
        followers[followeeId].insert({followerId, 1});
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followeeId].erase(followerId);
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
