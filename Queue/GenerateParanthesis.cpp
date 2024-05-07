// Generate Paranthesis - Queue based solution, pretty good performance
// in memory and time on leetcode
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string sol = "";
        vector<string> sols;
        if(n == 0) return sols;
        int num_closed = n;
        int num_open = n;
        queue<tuple<string, int, int>> q;
        q.push(make_tuple("", n, n));
        while(!q.empty())
        {
            tuple<string, int, int> comb = q.front();
            q.pop();
            string str = get<0>(comb);
            int num_open = get<1>(comb);
            int num_closed = get<2>(comb);
            if(num_open==0 && num_closed == 0)
            {
                sols.push_back(str);
            }
            else
            {
                if(num_open == num_closed)
                {
                    str.push_back('(');
                    num_open--;
                    q.push(make_tuple(str, num_open, num_closed));
                }
                else if(num_open == 0)
                {
                    str.push_back(')');
                    num_closed--;
                    q.push(make_tuple(str, num_open, num_closed));
                }
                else
                {
                    string sol1 = str;
                    string sol2 = str;
                    sol1.push_back('(');
                    sol2.push_back(')');
                    q.push(make_tuple(sol1, num_open-1, num_closed));
                    q.push(make_tuple(sol2, num_open, num_closed-1));
                }
            }
        }
        return sols;
    }


};
