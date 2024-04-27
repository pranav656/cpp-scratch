// LC338 - Counting Bits
// Brute force solution is to
// generate binaries for each of the number.
// Time Complexity : O(nlogn)

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1, 0);
        // O(n) solution, avoid recomputation
        // as patterns are repeated
        // 2 - 0010, 4-0100
        // 1 - 0001, 5-0101
        for(int i = 1; i<=n; i++)
        {
            //result[i] = result[i/2]+ i%2;
            // alternatively
            result[i] = result[i >> 1] + (i & 1);         
        }
        /*
        O(nlogn) solution
        for(int i = 0; i<=n; i++)
        {
            int x = i;
            int res=0;
            while(x != 0)
            {
                res = res + x%2;
                x = x/2;
            }
            result[i] = res;
        }*/

        return result;
    }
};
