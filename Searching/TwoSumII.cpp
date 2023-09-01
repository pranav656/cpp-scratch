// LC167: Two Sum 2
// Time complexity O(n), space complexity O(k)

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> res;
        int l = 0; int r = numbers.size() -1;
        while(l<r)
        {
            int sum = numbers[l]+numbers[r];
            if(sum <target)
            {
                l++;
            }
            else if(sum > target)
            {
                r--;
            }
            else
            {
                res.push_back(l+1);
                res.push_back(r+1);
                break;
            }
        }
        return res;
    }
};
