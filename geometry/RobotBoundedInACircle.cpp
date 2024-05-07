// LC1041 - Robot bounded in a circle
// The key idea behind this problem 
// is to do a limited simulation. If after a 
// round of simulation, the position remains
// the same or if the direction has changed, 
// it means there will be a cycle
// Case (Straight straight right): 
//R
//S
//S
// Case 2(Straight straight right left straight straight):
//RL
//SS
//SS
// Time complexity O(number of instructions)
// Space complexity O(1)
class Solution {
private:
public:
    bool isRobotBounded(string instructions) {
        // current position
        int posx = 0, posy = 0;
        // direction vector (initially pointing up)
        int degree = 0;
        for(auto & instruction : instructions)
        {
            if(instruction == 'G')
            {
                if(degree == 0) posy += 1;
                else if(degree == 90 || degree == -270) posx += 1;
                else if(degree == 180 || degree == -180) posy -= 1;
                else if (degree == -90 || degree == 270) posx -= 1;
            }
            else if (instruction == 'L')
            {
                degree -= 90;
                if(degree == -360) degree = 0;
            }
            else
            {
                // right
                // temporary variables for
                // rotation
                degree += 90;
                if(degree == 360) degree = 0;
            }
        }
        // if either position is unchanged or direction is changed
        return (((posx == 0) && (posy == 0)) || (degree != 0));
    }
};
