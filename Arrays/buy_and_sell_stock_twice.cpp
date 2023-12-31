/*

Question (EPI - 5.6): 
Given an array of share prices spread over different days,
determine the maximum profit that could have been obtained

Key Idea:
Basic Approach:
Go through the array and find the differences for every single 
possible day. The approach is O(n^2).

The optimized approach is that you calculate the minimum price 
that you have seen so far and see if the profit you obtain by selling
it at a particular day is greater than the current max.  The
time complexity is O(n) and the space complexity is O(1).

*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <limits>
#include <vector>

using namespace std;

int get_max_profit(std::vector<int>& prices)
{
    int max_profit = 0; 
    int min_price_seen_so_far = std::numeric_limits<int>::max();
    for (auto price : prices)
    {
       int current_profit = price - min_price_seen_so_far;
       if (current_profit > max_profit) max_profit = current_profit;
       if (price<min_price_seen_so_far)  min_price_seen_so_far = price; 
    }
    return max_profit;
}

int main() { 

    std::vector<int> prices = {310, 315, 275, 295, 260, 270, 290, 230, 255, 250};
    int max_profit = get_max_profit(prices);
    assert(max_profit == 30);
    return 0;
}
