
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
