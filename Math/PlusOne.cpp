class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> res;
        //increment one from start
        int carry = 1;
        int i =n-1;
        while(i >= 0)
        {
            if(carry+digits[i] > 9)
            {
                res.insert(res.begin(), 0);
                carry = 1;
            }
            else
            {
                res.insert(res.begin(), carry+digits[i]);
                carry = 0;
            }
            i--;
        }
        if(carry == 1) res.insert(res.begin(), 1);
        return res;
    }
};
