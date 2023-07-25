
#include <bits/stdc++.h>
/*
Given a string and a set of other string, find if a string is
constructible from the other set of strings by concatenating one another.
CanConstruct(abcd, {ab, abc, cd, def, abcd}) -> true
CanConstruct(skateboard, {bo, rd, ate, t, ska, sk, boar}) -> false
*/

using namespace std;

// Recursive approach: Search if the
// prefix occurs in the targe string, if yes slice the target string (remove the prefix)
// and recurse further. This does not work well when the string is long
// Time complexity is O(n^m *m) where n is the word bank length and m is the
// target length. Why? The height of the tree is going to be the size
// of the string m in the worst case. In case where there is a prefix match
// of size 1 consequtively. On every level of recursion you would also
// branch multiple trees if every word in the word bank was a prefix of
// the subsequent target strings. So, on each level, you would have to 
// n different recursions on each level, hence o(n^m). The multiplication
// by m is because we search for the occurence of the word in the target and slice the 
// target. This operation takes m time, so total complexity is O(n^m * m). Space 
// complexity is O(m*m) which is O(m) for the recursion tree and O(m) for every time
// you store a slice of a string in one of the recursion calls.
bool canConstructRec(string target, const vector<string>& wordBank)
{
    if(target.empty()) return true;
    for(string word : wordBank)
    {
       size_t found = target.find(word);
       if (found != string::npos && (found == 0))
       {
          string suffix = target.substr(word.size());
          if(canConstructRec(suffix, wordBank)) return true;
       }
    }

    return false;
}


// Below is the memoized implementation
// It's the same as the recursive implementation,
// just that the results of the recursion are stored in
// a memoized object and returned if it already exists, 
// preventing re-computation. The time complexity is 
// O(n*m*m), O(n*m) since we have stemmed the recursion
// with memoization, the multiplication with m is because
// of the search and slice operation. Space complexity is
// still O(m*m)
unordered_map<string, bool> memoization_table;

bool canConstructMem(string target, const vector<string>& wordBank)
{
    if(memoization_table.find(target) != memoization_table.end()) 
    {
        return memoization_table[target];
    }
    if(target.empty())
    {
        memoization_table[target] = true;
        return true;
    }
    for(string word : wordBank)
    {
       size_t found = target.find(word);
       if (found != string::npos && (found == 0))
       {
          string suffix = target.substr(word.size());
          if(canConstructMem(suffix, wordBank))
          {
              memoization_table[target] = true;
              return true;
          }
       }
    }
    memoization_table[target] = false;
    return false;   
}


int main() {
   cout<<canConstructRec("abcd", {"ab", "abc", "cd", "def", "abcd"});
   cout<<canConstructRec("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
   // This call will take forever in the recursive implementation
   //cout<<canConstructRec("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"});
   cout<<canConstructMem("abcd", {"ab", "abc", "cd", "def", "abcd"});
   cout<<canConstructMem("skateboard", {"bo", "rd", "ate", "t", "ska", "sk", "boar"});
   cout<<canConstructMem("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", {"e", "ee", "eee", "eeee", "eeeee"});
}
