
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>

/*
Problem (EPI12.5)
Find the nearest repeated entries in an array. 
for eg. s = all work and no play makes for no work no fun and no results
Second and third occurences of no is the correct answer. the distance between 
them is 2.

Straightforward Approach:
Go through all the elements in an array, check if any of the 
entries are equal and calculate the minimum distance between them. 
Update if the found minumum distance is smaller than the existing minimum distance.

Optimized approach:
As you go through the array, you can keep track of the index of the words you 
come across in a hashmap. If you find a duplicate, calculate the distance 
and update minimum distance if smaller. 

Clarification questions that can be asked during an interview:
Are the capitalized words same as the non capitalized ones (case sensitive)?

*/


int FindNearestRepetition(std::vector<std::string> paragraph)
{
    std::unordered_map<std::string, int> word_to_latest_idx;
    int min_distance = std::numeric_limits<int>::max();
    for (int i = 0; i <paragraph.size(); i++)
    {
       if(word_to_latest_idx.find(paragraph[i]) != word_to_latest_idx.end())
       {
           // replace these kinds of conditions with if statements
           int distance =  i - word_to_latest_idx[paragraph[i]];
           if(distance < min_distance)
           {
               min_distance = distance;
           }
       }
       word_to_latest_idx[paragraph[i]] = i;
    }
    return min_distance;
}

int main()
{
   std::vector<std::string> paragraph = {"All", "work", "and", "no", "play", "makes", "for", "no", "work", "no", 
                                         "fun", "and", "no", "results"};
   std::cout<<FindNearestRepetition(paragraph)<<std::endl;
    return 0;
}
