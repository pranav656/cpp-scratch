#include <bits/stdc++.h>

/*
Non Overlapping Intervals (LC435):

The brute force solution tries all possible cobinations of intervals
to see which one is the minimal, but the time complexity goes upto
O(2^n)

The key idea here is to figure our how to remove the intervals. First 
you sort the intervals in order of their starting points. This can also 
be done in the order of ending points. Now go through the intervals:
if the start of the next interval is greater than or equal to the end of the current
interval, then the next interval need not be removed, you update the end point to be checked
to the next interval and move on. If not, then you need to increment the count (one of the intervals need to
be removed). In order to choose which interval you need to remove, you need to take the minimal
end point. This is the key logic behind this problem. This removal leads to optimal solution.
See the following examples:

1.
    *....*
*-----* --> chose this interval 

2.

  *...* --> choose this interval  
*.......*
        
Time complexity: O(Nlogn)
Memory complexity O(N) where N is the number of intervals, this can be improved
by not creating a new struct to store the ordered intervals.

*/

using namespace std;

bool compare(const vector<int> a, const vector<int> b)
{
    return a[0] <= b[0];
}

int countErasuresOverlapIntervals(vector<vector<int> >& intervals)
{
    int count = 0;
    set<vector<int>, decltype(compare)*> ordered_intervals(compare);
    for (const auto& interval : intervals) {
        ordered_intervals.insert(interval);
    }

    int nstart = (*ordered_intervals.begin())[0];
    int nend = (*ordered_intervals.begin())[1];
    auto nit = next(ordered_intervals.begin());
    for (auto it = nit; it != ordered_intervals.end(); it++) {
        int start = (*it)[0];
        int end = (*it)[1];
        if (start >= nend) {
            nend = end;
        }
        else {
            count++;
            nend = min(end, nend);
        }
    }

    return count;
}

int main()
{
    vector<vector<int> > intervals = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 3 } };
    cout << countErasuresOverlapIntervals(intervals);
    return 0;
}
