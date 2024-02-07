// LC853 - Car Fleet

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cars;
        for(int i = 0; i<position.size(); i++)
        {
            double time = static_cast<double>((target - position[i]))/speed[i];
            cars.push_back({position[i], time});
        }
        sort(cars.begin(), cars.end());
        double maxTime = 0.0;
        int ans = 0;
        for(int i = cars.size() - 1; i >= 0; i--)
        {
            if(cars[i].second > maxTime)
            {
                ans++;
                maxTime = cars[i].second;
            }
        }
        return ans;
    }
};
