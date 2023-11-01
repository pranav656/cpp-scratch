// LC875 - Koko Eating Bananas
// The key idea is to look for a rate of eating
// which will lead to the minum number of hours. 
// you can start with a l and r end points (based on the
// range of the answer)
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int n = piles.size();
       // search range is between 1 and max of piles, can also 
       // keep r to the max range
       int l = 1, r = *max_element(piles.begin(), piles.end());
       int mid = 0;
       while(l <= r)
       {
           mid = (l+r)/2;
           unsigned long long sum = 0;
           for(auto b : piles)
           {
               // trick to get ceil, without using ceil
               // works also for corner cases
               sum += (b+mid-1)/mid;
           }
           if(sum > h)
           {
               // the number of hours taken
               // is more than allowed, so increase
               // the rate of eating
               l = mid + 1;
           }
           else
           {
               // the number of hours taken is less than
               // or equal to expected, so reduce
               // the rate of eating
               r = mid - 1;
           }
       }
       // return the inflection point
       // i.e where l>r
       return l;
    }
};
