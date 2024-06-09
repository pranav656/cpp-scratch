// LC2812 - Find the safest path in a grid 
// Brute Force approach:
// Search for all possible paths and
// for each path in the grid, find the 
// manhattan distance O(2^nn * n*n)
// and keep track of the minimum
// Optimized approach:
// Multisource BFS from thiefs to
// find the distances for each grid/
// Then do a Dijkstra's search for the
// maximum safe path.
// Time complexity: O(n^2) for BFS and
// O(n^2*log(n)) for best path
// Practical Applications of this type of
// problem:
// Path finding during Emergency evacuation procedures
// Autonomous navigation for robots in difficult terrains
// Urban planning : Redirect traffic towards non congensted areas
// Wildlife conservation: Find paths that avoid human visitors while 
// designing wildlife corridors.
class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        vector<vector<int>> dirs = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int n = grid.size();
        vector<vector<int>> distances_to_thief(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q_thief_distances;
        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < n; c++)
            {
                if(grid[r][c]) {
                    q_thief_distances.push({r, c});
                    distances_to_thief[r][c] = 0;
                }
            }
        }

        // Calculate minimum distances for
        // each grid position
        while(!q_thief_distances.empty())
        {
            auto [r, c] = q_thief_distances.front();
            q_thief_distances.pop();
            for(auto& dir : dirs)
            {
                int nr = r + dir[0]; int nc = c + dir[1];
                if(nr >= 0 && nr < n && nc>= 0 && nc < n && distances_to_thief[nr][nc] == INT_MAX)
                {
                       distances_to_thief[nr][nc] = distances_to_thief[r][c] + 1;
                       q_thief_distances.push({nr, nc});
                }
            }
        }

        // Use Dijkstra's to find maximum safeness path
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({distances_to_thief[0][0], {0, 0}});
        vector<vector<int>> maxSafeness(n, vector<int>(n, -1));
        maxSafeness[0][0] = distances_to_thief[0][0];
        while(!pq.empty())
        {
            auto [d, pos] = pq.top();
            pq.pop();
            int r = pos.first; int c = pos.second;
            if(r == n-1 && c == n-1) return d;
            for(auto& dir : dirs)
            {
                int nr = r + dir[0], nc = c + dir[1];
                if( nr >= 0 && nr < n && nc >= 0 && nc < n)
                {
                    // this computes the safeness of the path 
                    // to nr, nc
                    int safeness = min(d, distances_to_thief[nr][nc]);
                    if(safeness > maxSafeness[nr][nc])
                    {
                        maxSafeness[nr][nc] = safeness;
                        // push the path for further search
                        pq.push({safeness, {nr, nc}});
                    }
                }
            }
        }

        return -1;
    }
};
