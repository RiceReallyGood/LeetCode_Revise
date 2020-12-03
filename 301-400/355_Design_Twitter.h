#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() :totaltwitters(0) {}
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        userTwitters[userId].push_back({totaltwitters++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        priority_queue<Node> pq;
        int sz = userTwitters[userId].size();
        if(followees[userId].find(userId) == followees[userId].end() && sz > 0)
            pq.push(Node(userTwitters[userId][sz - 1].first, userTwitters[userId][sz - 1].second, userId, sz - 1));
        for(auto it = followees[userId].begin(); it != followees[userId].end(); it++){
            sz = userTwitters[*it].size();
            if(sz > 0){
                pq.push(Node(userTwitters[*it][sz - 1].first, userTwitters[*it][sz - 1].second, *it, sz - 1));
            }
        }
        
        vector<int> ret;
        while(ret.size() < 10 && !pq.empty()){
            Node n = pq.top();
            pq.pop();
            ret.push_back(n.tweetId);
            if(n.index > 0){
                pq.push(Node(userTwitters[n.userId][n.index - 1].first, userTwitters[n.userId][n.index - 1].second, n.userId, n.index - 1));
            }
        }

        return ret;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        followees[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }

private:
    int totaltwitters;
    unordered_map<int, vector<pair<int, int>>> userTwitters;
    unordered_map<int, unordered_set<int>> followees;

    class Node{
    public:
        Node(int order_, int tweetId_, int userId_, int index_) : order(order_), tweetId(tweetId_), userId(userId_), index(index_) {}
        int order;
        int tweetId;
        int userId;
        int index;
        friend bool operator<(const Node& n1, const Node& n2){
            return n1.order < n2.order;
        }
    };
};