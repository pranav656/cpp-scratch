// LC20 -  Valid Parenthesis
// Stack gives the simplest solution
// Just keep pushing elements into the stack 
// and popping them out when there's a bracket
// found. Add this to a map.
// Time complexity o(n). Space complexity O(1) or 
// number of types of brackets
class Solution {
public:
    unordered_map<char, char> m = { {')', '('}, {']', '['}, {'}', '{'} };
    bool isValid(string s) {
        stack<char> st;
        for(char c : s)
        {
            if(st.size() > 0)
            {
                if(st.top() == m[c])
                {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        // If all brackets are consumed
        if(st.size() > 0) return false;
        return true;
    }
};
