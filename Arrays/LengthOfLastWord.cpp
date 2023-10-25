// LC58 - Length of Last word
// Iterate from reverse of string
// and keep of a flag of when the word starts
class Solution {
public:
    int lengthOfLastWord(string s) {
        bool isWord = false;
        int count = 0;
       for(int i = s.size()-1; i>=0;i--)
       {
           if(s[i] == ' ' && isWord) break;
           if(s[i] != ' '){
               isWord = true;
               count++;
           }
       }
       return count;
    }
};
