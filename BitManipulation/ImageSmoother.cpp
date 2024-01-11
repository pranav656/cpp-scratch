// LC661 - This is a straightforward solution. The more interesting O(1) memory 
// solution is below. The avgs are stored in the first eight bits
// Since the inputs is within 255, this can be exploited for 
// optimized storage.
class Solution {
public:
    int calculate_avg_and_store(vector<vector<int>>& img, int r, int c)
    {
        int rows = img.size();
        int cols = img[0].size();
        int cnt = 0, sum = 0, avg = 0;
        for (int i = -1; i<=1; i++)
        {
            for(int j = -1; j<=1; j++)
            {
                if( r+i >= rows || c+j >= cols 
                    || r+i < 0 || c+j < 0)
                {
                    continue;
                }
                cnt++;
                sum += (img[r+i][c+j] & 255);
            }
        }
       
       avg = floor(sum/cnt);
       // 65280 is 0b1111111100000000
       avg = (avg << 8) & 65280;
       avg |= img[r][c];
       img[r][c] = avg;
       return avg;
    }


    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        for(int i = 0; i < img.size(); i++)
        {
            for(int j = 0; j < img[0].size(); j++)
            {
                calculate_avg_and_store(img, i, j);
            }
        }
        // extract averages from the stored array
        for(int i = 0; i < img.size(); i++)
        {
            for(int j = 0; j<img[0].size(); j++)
            {
                img[i][j] = img[i][j] >> 8;
            }
        }
        return img;
    }
};
