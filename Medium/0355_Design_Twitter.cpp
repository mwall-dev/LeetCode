struct Tweet {
    int userId;
    int tweetId;
};

class Twitter {

private:
    std::vector<Tweet> tweets;
    std::unordered_map<int, std::unordered_set<int> > followers;

public:
    /** Initialize your data structure here. */
    Twitter() {

    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets.emplace_back(Tweet{userId, tweetId});
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    std::vector<int> getNewsFeed(int userId) {
        
        // Get user followers and store iterator.
        const std::unordered_set<int>& user_followers = followers[userId];
        const auto end = user_followers.end();
        
        std::vector<int> most_recent_ten;
        int count = 0;
        
        for(int i = tweets.size() - 1; i >= 0; --i) {
            Tweet current_tweet= tweets[i];
            if(userId == current_tweet.userId ||
               user_followers.find(current_tweet.userId) != end) {
                
                most_recent_ten.push_back(current_tweet.tweetId);
                ++count;
            }
            if(count >= 10) break;
        }

        return most_recent_ten;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followers[followerId].insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
