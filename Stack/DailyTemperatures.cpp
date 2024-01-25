// LC739 - Daily Temperatures
// Monotonically Decreasing stack
// 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector result(temperatures.size(), 0);
        stack<pair<int, int>> s;
        for(int i = 0; i<temperatures.size(); i++)
        {
            int currTemp = temperatures[i];
            int currDay = i;
            while(!s.empty() && currTemp > s.top().second)
            {
                int prevDay = s.top().first;
                result[prevDay] = currDay - prevDay;
                s.pop();
            }
            s.push({currDay, currTemp});
        }

        return result;
    }
};
