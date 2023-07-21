/* 
Problem (EPI 16.1): 
Write a program that takes a final score and scores for individual plays
and returns the number of combination plays that return the final score

Solution:

This is a dynamic programming problem, Let's say you have scores
{2}, {2,3} and {2,3,7}. The DP table rows represent the scores
obtained only by {2}, only by {2,3} and only by {2,3,7}.
In that way we prevent duplicates. For the subsequent rows you
re-use results from the previous row for the same score.
The column j is basically representing the number of ways to
reach j.
*/

#include<bits/stdc++.h>
using namespace std;

int NumCombinationsForFinalScore(int final_score,
                                 const vector<int> individual_play_score)
{
   // initialize all scores to zero
   vector<vector<int>> num_combinations_for_score(individual_play_score.size(),
                                                  vector<int>(final_score+1, 0));
    for(int i = 0; i< individual_play_score.size(); i++)
    {
        // Only one way to reach score 0
        num_combinations_for_score[i][0] = 1;
        for(int j = 1; j<=final_score; j++)
        {
            int without_this_play = 
            // The condition is only to check if j>i
            i >= 1 ? num_combinations_for_score[i-1][j] : 0;
            int with_this_play = 
            // The condition is only to check if j>i
            j >= individual_play_score[i] ? num_combinations_for_score[i][j - individual_play_score[i]] : 0;
            num_combinations_for_score[i][j] = without_this_play + with_this_play;
        }
    }
    // Return the last element for the answer since it's the
    // number of combinations after the completion of the 
    // DP table
    return num_combinations_for_score.back().back();
}

int main()
{
  vector<int> scores = {2, 3, 7};
  cout<<NumCombinationsForFinalScore(12, scores);
}
