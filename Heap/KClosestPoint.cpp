// LC973 - K closes points to Origin
// Heap solution 
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // distance, px, py
        vector<vector<int>> triplets;
        for (auto& p : points)
        {
            triplets.push_back({p[0]*p[0] + p[1]*p[1], p[0], p[1]});
        }
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>> > pq
        (triplets.begin(), triplets.end());
        vector<vector<int>> res;
        while(k--)
        {
            auto distance_point = pq.top();
            pq.pop();
            res.push_back({distance_point[1], distance_point[2]});
        }
        return res;
    }
};
