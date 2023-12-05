#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    string input;
    map<int, int> copies;
    while (getline(cin, input))
    {
        string card_dummy, colon_dummy;
        int card_number;
        stringstream s(input);
        s >> card_dummy >> card_number>> colon_dummy;
        string ip;
        set<int> winners;
        while(s >> ip && ip != "|")
        {
            winners.insert(stoi(ip));        
        }
        int found_cards =  0;
        while(s >> ip)
        {
            if(winners.count(stoi(ip)))
            {
                found_cards++;
            }
        }
        // increment copies of the 
        // current card number
        copies[card_number]++;
        // Key idea: find number of copies of current card
        // all copies will need to be updated 
        // Eg. if 1 has 2,3
        // all copies of 2, 3 need
        // to be updated with the same number
        // of cards
        int number_to_add = copies[card_number];
        for(int i = 1; i<=found_cards;i++)
        {
            copies[card_number+i] += number_to_add; 
        }
        ans += number_to_add;
    }
    cout<<ans<<endl;
}
