// Q: Given a string, count the number of subsequences of the form
// AiBjCk, consisting of i A characters, consisting of j B characters, 
// consisting of k C characters. 
// The brute force solution is trying to generate
// all possible sequences of AiBjCk which is going to take a lot of time. 
// 
// The key insight is to recognize that this can be thought of a binary
// combination problem, either you choose a character or you don't. Let's
// say you have aaa, there are seven possible combinations of aaa's that you
// can generate. The total count is 8 if you take the possibility of no a's. 
// Based on that logic, if the current character is 'a', either it starts
// a new series of a, or it's a part of 'a' subsequences or it's not a part
// of the 'a' subsequences. Similarly for b, it starts a new sequence of
// characters with 'a' count subsequences or it is already a part of
// 'b' subsequence or it is not a part of 'b' subsequeneces. You 
// can apply the same logic for c. Whe you reach the end of the string
// the count c is the total number of occurrences
// Space complexity is O(1) and time
// complexity is O(n);

#include <bits/stdc++.h>

using namespace std;
int CountSubsequences(string s)
{
    int count_a = 0, count_b = 0, count_c = 0;
    for(int i = 0; i<s.size(); i++)
    {
            if(s[i] == 'a')
            {
                count_a = 1 + 2*count_a;
            }

            if(s[i]== 'b')
            {
                count_b = count_a + 2*count_b;
            }

            if(s[i] == 'c')
            {
                count_c = count_b + 2*count_c;
            }
    }

    return count_c;
}

int main() { 
    cout<<CountSubsequences("abc")<<endl;
    cout<<CountSubsequences("aabc")<<endl;
    cout<<CountSubsequences("abbc")<<endl;
    cout<<CountSubsequences("abcabc")<<endl;
    return 0;
}
