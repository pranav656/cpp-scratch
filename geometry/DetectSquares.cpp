// LC2013 - Detect Squares
// Insert - O(n)
// Count - O(n^2), TODO: O(n) solution
class DetectSquares {
    private:
        
        map<int, map<int, int>> store;

public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        store[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int ans = 0;
        int x1 = point[0];
        int y1 = point[1];

        for(auto x = store.begin(); x!= store.end(); x++)
        {
            map<int, int> yPoints = x->second;
            for(auto y = yPoints.begin(); y != yPoints.end(); y++)
            {
                // consider point as diagnonal
                int x3 = x->first;
                int y3 = y->first;

                // check if point is really diagonal
                if(abs(x3-x1) == 0 || (abs(y3-y1) != abs(x3-x1) ))
                {
                    continue;
                }
                ans += store[x3][y3] * store[x3][y1] * store[x1][y3];
            }
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
