#include<bits/stdc++.h>

using namespace std;

int main()
{
    int ans = 0;
    string input;
    while (getline(cin, input))
    {
        string card_dummy, cardno_dummy;
        stringstream s(input);
        s >> card_dummy >> cardno_dummy;
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
        if(found_cards > 0)
        {
            ans+= pow(2, found_cards-1);
        }
    }
    cout<<ans<<endl;
}
