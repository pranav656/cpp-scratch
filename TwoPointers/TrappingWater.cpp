// LC42 Trapping Rain Water
// The key idea is to realize that
// the water stored at location i 
// can be given by max(l, r) - h[i] >=0
// l and r is the max height from the
// left and right at the given position.
// You could have a O(n) and O(1) memory solution

class Solution {
public:
    int trap(vector<int>& height) {
      vector<int> max_l(height.size(), 0);
      vector<int> max_r(height.size(), 0);
      vector<int> water_trap(height.size(), 0);
      int max_left = 0, max_right = 0;
      for(int i = 0; i< height.size(); i++)
      {
          max_l[i] = max_left;
          // cout<<max_l[i]<<" ";
          max_left = max(max_left, height[i]);
      }
      //cout<<endl;

      for(int i = height.size()-1; i>=0; i--)
      {
          max_r[i] = max_right;
          max_right = max(max_right, height[i]);
      }
      
      int ans = 0;
      for(int i = 0; i<height.size(); i++)
      {
          int water_store_at_i = min(max_l[i], max_r[i]) - height[i];
          //cout<<water_store_at_i<<" ";
          if(water_store_at_i > 0)
          {
              ans += water_store_at_i;
          }
      }
      //cout<<endl;

      return ans;

    }
};
