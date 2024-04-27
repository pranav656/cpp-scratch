// LC252 - Meeting Roms
// Free Neetcode link: https://neetcode.io/problems/meeting-schedule
// Sort the intervals first and then check if the
// end of current interval overlaps with start
// of next interval. Time complexity : O(nlogn) for sorting
// + O(n) for traversing the time intervals.
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(), 
             intervals.end(), [](const Interval& x, const Interval& y)
             {
                return x.start < y.start;
             });
        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i].start < intervals[i-1].end) return false;
        }
        return true;
    }
};
