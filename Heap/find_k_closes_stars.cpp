#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>

/*

Question (EPI 10.4): 
Compute k closest stars to earth

Key Idea:
Straightforward approach:
Go through the list, compute distance for each element, and sort by distance.
Time complexity is O(nlogn)

Optimized approach:
Use a max heap to keep track of k closest stars. Time complexity is O(nlogk) and 
space complexity is O(k).

*/

struct Star{
  bool operator<(const Star& that) const
  {
     return distance()<that.distance();
  }
  double distance () const
  {
      return std::hypot(x, y, z);
  }
  float x, y, z;
};

std::vector<Star> find_k_closest_stars(std::vector<Star> stars, int k)
{
    std::priority_queue<Star> heap;

    for (auto &star : stars)
    {
        heap.emplace(star);
        if(heap.size()==k+1)
        {
            heap.pop();
        }
    }
    std::vector<Star> closest_stars;
    while(!heap.empty())
    {
        closest_stars.emplace_back(heap.top());
        heap.pop();
    }
    return closest_stars;
}

int main()
{ 
   std::vector<Star> stars = {{0,0,0}, {0,0,1}, {3, 4, 5}, {1,1,0}, {7,8,9}};
   auto closest_stars = find_k_closest_stars(stars, 3);
   for(auto star : closest_stars)
    {
       std::cout<<star.x<<","<<star.y<<","<<star.z<<std::endl;   
    }
   return 0;
}
