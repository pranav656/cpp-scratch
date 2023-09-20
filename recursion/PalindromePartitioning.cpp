class Solution {


public:
bool IsPalindrome(string& s, int l, int r)
{
    while(l<r)
    {
        if(s[l] != s[r])
            return false;
        l++; r--;
    }
    return true;
}

void partition_helper(string& s, vector<vector<string>>& solutions, 
                      vector<string>& sol,
                      int i)
{
    if (i >= s.size())
    {
        solutions.push_back(sol);
        return;
    }
    for(int j = i; j < s.size(); j++)
    {
        if(IsPalindrome(s, i, j))
        {
            sol.push_back(s.substr(i, j-i+1));
            partition_helper(s, solutions, sol, j+1);
            sol.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) 
{
       vector<vector<string>> solutions;
       vector<string> part;
       partition_helper(s, solutions, part, 0);
       return solutions;
}


};
