// LC9 - Palindrome number
// reverse the second half of the number and check if it's
// same as the first half. Time complexity is the number of 
// digits. Space complexity is half the size of the input number
// used to store the reverse
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x%10 == 0 && x!= 0)) return false;
        int reversed = 0;
        // logic to reverse second half
        while(x > reversed)
        {
            reversed = reversed*10 + x%10;
            x /= 10;
        }
        // example odd length 11311 the reverse comes to 113
        // so ignore the last digit by 10 division
        return x == reversed || x == reversed/10;
    }
};
