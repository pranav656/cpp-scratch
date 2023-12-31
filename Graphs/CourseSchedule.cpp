/*

Question (Blind75): 
Course schedule. Given a number of courses that you need to complete
Each course has a prerequirisite given by an input array.
https://leetcode.com/problems/course-schedule/description/

Solution:

The problem basically involves figuring out if a cycle will ever occur 
in the graph. You don't need a complext data structure, but just a map taking the course
as key and the prerequisites. 

Do a depth first search if there are any cyclical dependencies on every course.
It could be that there are many separate graphs with different dependencies for each of the courses.
If any of them return false, then it's not possible to complete the given number of courses.


DFS Logic:
As you visit every node, check if that node has any pre-requisites. If there
are no prerequisites it means that the course can be completed and you return
true.
If there are pre-requites, you do a DFS on that.

You return false only in case where you detect a loop. 
How do you detect a loop?
You keep track of the visited nodes in a set and if you come across the node again,
then then you return false. Note that you can remove node from the visited list once
you have the result for the dfs traversal for each of it's prereuisites.

If any of the prerequisites during the DFS return false, then you can return false.
If not then you can be sure that the traversals went okay and then you can remove the 
node from the visited list and make the pre-requisite map empty so that future traversals 
don't need to perform the same operation again

*/

#include <bits/stdc++.h>

using namespace std;

bool dfs(unordered_map<int, vector<int>>& prereqMap, unordered_set<int>& visited, 
         int course)
{
   // A loop has been detected so return false
   // since the courses are cyclically dependent on 
   // each other
   if(visited.find(course) != visited.end())
   {
       return false;
   }
   // If the course has no prerequisite (empty array), then it can be completed
   if(prereqMap[course].empty())
   {
       return true;
   }
   visited.insert(course);
   // Run DFS on the prerequisite course and see if they
   // can be completd
   for (auto prereq_course : prereqMap[course])
   {
       if (!dfs(prereqMap, visited, prereq_course)) return false;
   }
   // remove the element from
   // the visited set since it's been visited already
   visited.erase(course);
    // make the array empty since we know that it 
    // can be completed, and to avoid re-computation
    prereqMap[course] = vector<int>{};
    return true;
}

bool canFinish(int numCourses, vector<vector<int>> prereq)
{
    unordered_map<int, vector<int>> prereqMap;
    // build an empty prerequisite map
    for(int i = 0; i<numCourses; i++)
    {
         prereqMap[i] = vector<int>{};      
    }
    //construct the prerequisite map with input
    for (auto course_pair:prereq)
    {
       prereqMap[course_pair[0]].push_back(course_pair[1]);
    }
    // Do a DFS for every single course and obtain result
    unordered_set<int> visited;
    for(int i = 0; i<numCourses; i++)
    {
            if (!dfs(prereqMap, visited, i)) return false;
    }
    return true;
}
/*
This one is the same approach as above, but
is much faster due to use of vectors
in place of hashmaps and sets.
class Solution {
public:
    vector<vector<int>> adjacency_list;
    vector<int> visited;
    bool cycle_detected(int node)
    {
        if(visited[node]) return true;
        visited[node] = 1;
        for(int nei : adjacency_list[node])
        {
            if(cycle_detected(nei)) return true;
        }
        adjacency_list[node].clear();
        visited[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        adjacency_list = vector<vector<int>>(numCourses, vector<int>{});
        visited = vector<int>(numCourses, 0);
        for(auto& pre : prerequisites)
        {
            adjacency_list[pre[1]].push_back(pre[0]);   
        }
        for(int i = 0; i<numCourses; i++)
        {
            if(cycle_detected(i)) return false;
        }
        return true ;
    }
};
*/

int main() { 
    vector<vector<int>> tc1 = {{1,0}};
    vector<vector<int>> tc2 = {{1,0}, {0, 1}};
    cout<<canFinish(2, tc1);
    cout<<canFinish(2, tc2);
    return 0;
}
