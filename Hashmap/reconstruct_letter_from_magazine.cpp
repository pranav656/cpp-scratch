
#include <iostream>
#include <iterator>
#include <memory>
#include <limits>
#include <cmath>
#include <cassert>
#include <vector>
#include <random>
#include <unordered_map>

/*

Question (EPI 12.2): 
Is letter constructible from magazine?

Solution:
Straight forward approach:
Construct a hashmap with character frequence from both the 
letter and magazine. If the letter frequency of any one 
of the characters from the letter exceeds the character
frequency from the magazine, return a false, else return true.
But this solution goes through the characters from the magazine completely
which is unnecessary

Optimized approach:
make a single pass over the letter and store the character frequency.
Now as you iterate over the magazine keep reducig the count and when the 
character frequency map is completely zero, you can exit the loop.
If the character frequency map is not empty by the time you pass the 
entire magazine it means that
The space complexity is O(L) where L is the number of distinct
characters in the letter. 
Time complexity is O(m+l) where m and l are the sizes of the letter and magazine respectively.
In the worst case you have to pass over the entire magazine during the second pass
*/

bool IsLetterConstructibleFromMagazine(std::string letter, std::string magazine)
{
    std::unordered_map<char, int> char_freq;
    for (char c : letter) {
        char_freq[c]++;
    }

    for (char c : magazine)
    {
       if(char_freq.find(c) != char_freq.end())
       {
           char_freq[c]--;
           if(char_freq[c] == 0)
           {
               char_freq.erase(c);
               if(char_freq.empty())
               {
                   return true;
               }    
           }
       }
    }
    return false;
}

int main()
{
    std::cout<<IsLetterConstructibleFromMagazine("abc", "cba")<<std::endl;
    std::cout<<IsLetterConstructibleFromMagazine("abcd", "cba")<<std::endl;
    std::cout<<IsLetterConstructibleFromMagazine("abcdd", "cbad")<<std::endl;
    return 0;
}
