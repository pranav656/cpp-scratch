// LC 210 - Course Schedule II
// This problem is a variation of Course Schedule 1
// except that this time we have to print the
// order of in which the courses should be taken.
// While doing the DFS, you can keep track of the
// courses completed first, and push it
// into the front of the vector since it's DFS. 
// In this way you are building the solution in a 
// topological order.
// Time complexity is same as DFS. 

class Solution {
public:
    vector<vector<int>> adjacency_list;
    // variable to find cycles
    vector<int> visited;
    // vector which stores the answer
    vector<int> ans;
    // variable to ensure courses that are completed
    // are not processed again.
    vector<int> course_completed;

    bool cycle_detected(int course)
    {
        // If the course has been completed already
        if(course_completed[course]) return false;
        if(visited[course]) return true;
        visited[course] = 1;
        for(int i =0;  i<adjacency_list[course].size();i++)
        {
            if(cycle_detected(adjacency_list[course][i])) return true;
        }
        visited[course] = 0;
        course_completed[course] = 1;
        // insert into front to preserve
        // order of doing courses
        ans.insert(ans.begin(), course);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        adjacency_list = vector<vector<int>>(numCourses, vector<int>{});
        visited = vector<int>(numCourses, 0);
        course_completed = vector<int>(numCourses, 0);
        for(auto& pre: prerequisites)
        {
            adjacency_list[pre[1]].push_back(pre[0]);
        }
        for(int i = 0; i<numCourses; i++)
        {
            if(cycle_detected(i))
            {
                return vector<int>{};
            }
        }
        return ans;
    }
};
