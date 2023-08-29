
/*

https://open.kattis.com/contests/cgbkbq/problems/dunglish
TOSOLVE: Works only for the basic cases, not fully accepted solution
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, vector<string>> correct_words_dict;
    unordered_map<string, vector<string>> incorrect_words_dict;
    vector<string> sentence;
    int num_words;
    cin>>num_words;

    for(int i = 0; i<num_words; i++)
    {
        string word;
        cin>>word;
        sentence.push_back(word);
    }

    int num_translations;
    cin>>num_translations;
    for(int i = 0; i<num_translations; i++)
    {
        string dutch_word, english_word, c_or_w;
        cin>>dutch_word>>english_word>>c_or_w;
        if(c_or_w == "correct")
        {
            correct_words_dict[dutch_word].push_back(english_word);
        }
        else if(c_or_w == "incorrect")
        {
            incorrect_words_dict[dutch_word].push_back(english_word);
        }
    }
    int total_combinations = 1;
    int total_correct_combinations = 1;
    int total_incorrect_combinations = 0;
    for(auto word : sentence)
    {
       total_combinations *= correct_words_dict[word].size() +  incorrect_words_dict[word].size();
       total_correct_combinations *= correct_words_dict[word].size();
    }
    total_incorrect_combinations = total_combinations - total_correct_combinations;

    vector<string> only_potential_answer;
    if(total_combinations == 1)
    {
        for(auto word: sentence)
        {
            if(correct_words_dict[word].size() != 0)
            {
                only_potential_answer.push_back(correct_words_dict[word][0]); 
            }
            else if (incorrect_words_dict[word].size() != 0)
            {

                only_potential_answer.push_back(incorrect_words_dict[word][0]);
            }
        }
        for(int i = 0; i<only_potential_answer.size(); i++)
        {
                cout<<only_potential_answer[i];
                if(i != only_potential_answer.size() -1 )
                {
                    cout<<" ";
                }       
        }
        cout<<endl;
        if(total_incorrect_combinations == 1)
        {
            cout<<"incorrect"<<endl;
        }
        else
        {
            cout<<"correct"<<endl;
        }
    }
    else 
    {
        cout<<total_correct_combinations<<" "<<"correct"<<endl;
        cout<<total_incorrect_combinations<<" "<<"incorrect"<<endl;
    }
    
    
    return 0;
}
