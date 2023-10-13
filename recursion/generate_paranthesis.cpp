// LC22 - Generate Paranthesis
// This problem requires the following understanding to
// be solved
// 1. When number of open and closed brackets are equal
// you can only start with (
// 2. If number of open left is zero, then you can use
// only closed.
// 3. In other cases, you can use both open and closed braces.
// Since n = 8, a simple recusion works. Time complexity O(2^n).
// Space complexity O(N) and recursive stack space.
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        int num_closed_brackets = n;
        int num_open_brackets = n;
        string sol = "";
        vector<string> sols;
        helper(num_open_brackets, num_closed_brackets,
               sol, sols);
        return sols;
    }

    void helper(int num_open, int num_closed, string sol, vector<string>& sols)
    {
        // When number of open and closed brackets
        // are equal, 
        if(num_open == 0 && num_closed == 0)
        {
            sols.push_back(sol);
            return;
        }
        // When number of brackets are equal
        else if(num_open == num_closed)
        {
            sol.push_back('(');
            num_open--;
            helper(num_open, num_closed, 
                    sol, sols);
        }
        // When number of open brackets left 
        // is zero
        else if(num_open == 0)
        {
            sol.push_back(')');
            num_closed--;
            helper(num_open, num_closed, 
                    sol, sols);
        }
        else
        {
            // other cases where both are 
            // possible
            string sol1 = sol;
            string sol2 = sol;
            sol1.push_back('(');
            sol2.push_back(')');
            helper(num_open-1, num_closed, sol1, sols);
            helper(num_open, num_closed-1, sol2, sols);
        }
    }
};
