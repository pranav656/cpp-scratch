//LC78 subsets - recursive
// Time Complexity - O(n.2^n). This
// is because you have to generate all the n
// combinations
class Solution {
public:
    void subsetsHelper(vector<int>& nums, vector<int> output, int idx, 
    vector<vector<int>>& ans)
    {
        if(idx == nums.size()) 
        {
            ans.push_back(output);
            return;
        }
        subsetsHelper(nums, output, idx+1, ans);
        int element = nums[idx];
        output.push_back(element);
        subsetsHelper(nums, output, idx+1, ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        subsetsHelper(nums, output, 0, ans);
        return ans;
    }
};

// generate 2^n combinations
class Solution {
public:

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int num = pow(2, nums.size()) - 1;
        cout<<"num:"<<num<<endl;
        for(int i = 0; i<=num; i++)
        {
            vector<int> tmp;
            // generate combinations based on comb binary
            int idx = 0, comb = i;
            while(idx < nums.size() && comb)
            {
                if(comb & 1)
                {
                    tmp.push_back(nums[idx]);
                }
                comb = comb >> 1;
                idx++;
            }
            ans.push_back(tmp);
        }

        return ans;
    }
};
