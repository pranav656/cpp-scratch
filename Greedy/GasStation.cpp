// LC134 (Gas station)
// Brute force solution would be to go
// through each location and check if the round 
// trip leads to a net zero cost. O(n) solution
// is possible with the following:
// Key insights:
// 1. Find the differential costs at each point
// 2. If total of gas is less than total of costs, then
// a solution is not possible
// 3. Track total costs at each location, if it gets
// less than 0, it cannot be a solution.
// 4. In one iteration, you can figure out if 
// the location is valid or not, based on the 
// if the total cost becomes less than 0. Exploit
// the fact that there is only one solution.
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0;
        int totalCosts = 0;
        int n = gas.size();
        for(int i = 0; i<n; i++)
        {
            totalGas += gas[i];
            totalCosts += cost[i];
        }
        if(totalGas < totalCosts) return -1;

        int total = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            total += gas[i] - cost[i];
            if(total < 0)
            {
                total = 0;
                start = i+1;
            }
        }
        return start;
    }
};
