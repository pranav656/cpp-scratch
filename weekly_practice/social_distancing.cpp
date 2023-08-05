
#include <iostream>
#include <algorithm>
#include <limits>
#include <string>
#include <vector>
#include <unordered_map>

/*
https://open.kattis.com/contests/y53fv3/problems/socialdistancing2


*/

int get_previous_candidate(int i, int num)
{
    if(i == 0)
    {
        return num-1;
    }
    return i-1;
}

int get_next_candidate(int i ,int num)
{
    if(i == num-1)
    {
        return 0;
    }
    return i+1;
}

int get_max_filled(std::vector<int>& table)
{
    int max_possible = 0;
    for (int i = 0; i<table.size(); i++ )
    {
         if(table[i] == 0)
         {
             if(table[get_previous_candidate(i, table.size())] == 0 && table[get_next_candidate(i, table.size())] == 0)
             {
                 table[i] = 1;
                 max_possible++;
             }
         }
    }
    return max_possible;
}

int main()
{
   int chairs, people;
   std::cin>>chairs>>people;
   std::vector<int> filled_chairs(chairs, 0);
    for(int i = 0; i<people; i++)
   {
      int filled;
      std::cin>>filled;
      filled_chairs[filled-1] = 1;
   }
    std::cout<<get_max_filled(filled_chairs)<<std::endl;

    return 0;
}
