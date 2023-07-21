
#include <bits/stdc++.h>

/*
Problem (EPI 18.1)
Search a maze if there exists a path from 
A to B in a maze.
Approaches:
Find all possible paths from A to B and try each one 
of them, but the time complexity of such an approach would be very high
We can use a depth-first search or a breadth first search.
At some point during the search if we discover the exit vertex then there exists
a path from the entry to the exit, we return true.
Once we visit a path we mark the path as visited by marking it black (there are
other ways to do it by using a separate structure, bit this is optimal).
The BFS search is more optimal in the sense that it will give you
the shortest path from the entry to the exit (don't understand how yet).


*/

using namespace std;

typedef enum { KWhite, KBlack } Color;

struct Coordinate {
   bool operator ==(const Coordinate& that) const {
       return x == that.x && y == that.x;
   }
   int x, y;
};

bool SearchMazeHelper(const Coordinate& curr, const Coordinate& dest, vector<vector<Color>>& maze, vector<Coordinate>& path)
{
    // Last check is not safe since if this path is reached then it's undefined behavior if it goes out of bounds of 
    // the maze array
    if(curr.x < 0 || curr.x >= maze.size() || curr.y < 0 || curr .y >= maze[curr.x].size() || maze[curr.x][curr.y] != Color::KWhite)
    {
        return false;
    }
    path.emplace_back(curr);
    // mark this path as visited using the color
    maze[curr.x][curr.y] = Color::KBlack;
    if(curr == dest)
    {
        return true;
    }
    const vector<Coordinate> possible_moves{{curr.x + 1, curr.y}, {curr.x, curr.y + 1}, {curr.x - 1, curr.y}, {curr.x , curr.y - 1}};
    for (const auto& move : possible_moves)
    {
         // If any of the paths are succesful return true
         if ( SearchMazeHelper(move, dest, maze, path)) {
             return true;
         }  
    }
    // If none of the conditions above are true, then return false
    path.pop_back();
    return false;
}

vector<Coordinate> SearchMaze(vector<vector<Color>> maze, const Coordinate& s, const Coordinate& d)
{
   vector<Coordinate> path;
   SearchMazeHelper(s, d, maze, path);
   return path; 
}

int main()
{
    Coordinate s = {0, 0};
    Coordinate d = {2, 2};
    // path to destination available 
    vector<vector<Color>> maze = {{Color::KWhite, Color::KWhite, Color::KWhite}, 
     {Color::KWhite, Color::KWhite, Color::KWhite}, 
     {Color::KWhite, Color::KWhite, Color::KWhite}};
    // no path to destination
    vector<vector<Color>> maze1 = {{Color::KWhite, Color::KWhite, Color::KWhite}, 
     {Color::KWhite, Color::KWhite, Color::KBlack}, 
     {Color::KWhite, Color::KBlack, Color::KWhite}};
    auto path = SearchMaze(maze, s, d);

    for (auto& c : path)
    {
       std::cout << c.x <<c.y <<std::endl;    
    }
    return 0;
}
