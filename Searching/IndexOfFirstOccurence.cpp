// LC28 - Find the Index of the First Occurrence in a String
// Check where the first character occurs in the target string
// and search for the complete string from that point. 
// If the full word is found return the starting index
// Time complexity is O(m*n), where m and n are the number of
// characters in each word
class Solution {
public:
    int strStr(string haystack, string needle) {
        char c = needle[0]; int start = INT_MAX; bool match_found = true;
        for(int i = 0; i<haystack.size(); i++)
        {
            if(haystack[i] == c)
            {
                match_found = true;
                for(int j = 1; j< needle.size(); j++)
                {
                    //cout<<needle[j];
                    if(i+j >= haystack.size())
                    {
                        match_found = false;
                    }
                    else if(haystack[i+j] != needle[j])
                    {
                        match_found=false;
                    }
                }
                if(match_found) 
                {
                    return i;
                }
            }
        }
        return -1;
    }
};
