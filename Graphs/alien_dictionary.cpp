
#include <bits/stdc++.h>

/*

Problem Alien Dicionary:
Given a new alien language. It's in English but the order
of the words are changed. You are given a list of words
that are in lexographically sorted order. The goal is to
written unique words that are in increasing order. If there is no solution,
then you writen the empty string. If there is more than one solution,
return one of them.


Solution:
First construct the relationship between words.
If there are two different sets, then we can merge 
them into one set and return. When constructing the graph
do a post order traversal since it will ensure that the ordering is correct.
Doing DFS in a traditional manner can result in invalid string being
formed in case there is a relationship like this:
A-->B-->C
A-->C


*/


using namespace std;
bool dfs(unordered_map<char, set<char>> adjacency_list, unordered_map<char, bool>& visited, char c, string& res)
{
       if(visited.find(c) != visited.end()) {
           return visited[c];
       }
       visited[c] = true;
       if(adjacency_list.find(c) != adjacency_list.end())
       {
          // Do DFS on every single neighbour
          for (auto neighbour : adjacency_list[c])
          {
             if (dfs(adjacency_list, visited, neighbour, res))
             {
                 return true;
             }
          }
       }

        visited[c] = false;
        // Update result after traversal, post order traversal
        res.insert(res.end(), c);
        return false;
}

string AlienOrder(vector<string> words)
{
   string res;
   // use set to avoid duplicates
   unordered_map<char, set<char>> adjacency_list;
    // make the map with empty sets
   for(auto& word : words)
   {
       for (auto& c : word)
       {
           adjacency_list[c] = set<char>();
       }
   }
   // create adjaceny list
   // of neighbours for each characters
   for (int i = 0; i<words.size()-1;i++)
   {
      string w1 = words[i];
      string w2 = words[i+1];
      size_t min_len = min(w1.size(), w2.size());
      // This is one of the base conditions for lexographical ordering.
      // If it's not followed, then no solution exists
      if((w1.size() > w2.size()) && (w1.substr(0, min_len) == w2))
      {
          return "";
      }

      for (int j = 0; j < min_len; j++)
      {
          // the first mismatch of words
          // indicates topological ordering and the rest
          // don't matter, so break out
          if(w1[j] != w2[j])
          {
              adjacency_list[w1[j]].insert(w2[j]);
              break;
          }
      }
   }

   unordered_map<char, bool> visited;

   for (auto it : adjacency_list)
   {
       if (dfs(adjacency_list, visited, it.first, res)) return "";
   }
   // Since it's post order traversal
   // reverse the result
   reverse(res.begin(), res.end());
   return res;
}

int main()
{
   vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
    cout<<AlienOrder(words);
   return 0;
}



// Alien Dictionary
// Approach (Solution from neetcode
// commented with explanation):
// Build the graph of words
// 
class Solution {
private:
    // adjacency list of list of words
    unordered_map<char, unordered_set<char>> adj;
    // to detect for cycles, when cycles
    // are detected, then a solution is not possible
    unordered_map<char, bool> visited;
    string result;
public:
    string foreignDictionary(vector<string>& words) {
        for(const auto& word : words)
        {
            for(char ch : word)
            {
                // initializes the adjacency
                // list with the characters
                adj[ch];
            }
        }

        // iterate through the words, two at a time
        for(size_t i = 0; i < words.size()-1; ++i)
        {
            const string& w1 = words[i];
            const string& w2 = words[i+1];
            size_t minLen = min(w1.length(), w2.length());

            // base case where there is no solution:
            // if words next to each have a prefix
            // that is equal and if the first word
            // has larger length, it violates
            // the basic assumption of the problem
            // that the input list is lexographically 
            // sorted. So, return an empty string.
            if (w1.length() > w2.length() && 
                w1.substr(0, minLen) == w2.substr(0, minLen) )
            {
                return "";
            }
            for(size_t j = 0; j < minLen; ++j)
            {
                // on first mismatch, we
                // know that char at position j
                // of word 1 is before char at 
                // position j of word 2
                if(w1[j] != w2[j]) {
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

                    for(const auto& pair: adj)
            {
                // this DFS function does 
                // two things, it build the result
                // and checks if there exists a cycle
                // in the graph, if cycle is detected
                // return "" as solution is not possible
                if(dfs(pair.first))
                {
                    return "";
                }
            }

            // we do this reverse because
            // the dfs is done in post order. 
            // The postorder traveral ensures that
            // the ordering of the characters in
            // the graph is respect
            reverse(result.begin(), result.end());
            return result;
    }

    // does two things: ensures no cycle
    // builds the result
    bool dfs(char ch)
    {
        // cycle detection
        if(visited.find(ch) != visited.end())
        {
            return visited[ch];
        }

        visited[ch] = true;
        for(char next : adj[ch])
        {
            if(dfs(next)) {
                return true;
            }
        }
        visited[ch] = false;
        result.push_back(ch);
        return false;
    }
};
