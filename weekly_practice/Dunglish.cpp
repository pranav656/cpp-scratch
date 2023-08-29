
/*

https://open.kattis.com/contests/cgbkbq/problems/dunglish
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<string, int> correct_words_cnt;
    unordered_map<string, int> incorrect_words_cnt;
    unordered_map<string, string> translation;
    int num_words;
    cin>>num_words;
    vector<string> sentence(num_words);
    for(int i = 0; i<num_words; i++)
    {
        cin>>sentence[i];
    }

    int num_translations;
    cin>>num_translations;
    for(int i = 0; i<num_translations; i++)
    {
        string dutch_word, english_word, c_or_w;
        cin>>dutch_word>>english_word>>c_or_w;
        translation[dutch_word]=english_word; 
        if(c_or_w == "correct")
        {
            correct_words_cnt[dutch_word]++;
        }
        else if(c_or_w == "incorrect")
        {
            incorrect_words_cnt[dutch_word]++;
        }
    }
    unsigned long long total_combinations = 1;
    unsigned long long total_correct_combinations = 1;
    for(auto word : sentence)
    {
       total_combinations *= correct_words_cnt[word] +  incorrect_words_cnt[word];
       total_correct_combinations *= correct_words_cnt[word];
    }
    unsigned long long total_incorrect_combinations = total_combinations - total_correct_combinations;

    if(total_combinations == 1)
    {
        for(auto word: sentence)
        {
            cout<<translation[word]<<" ";
        }
        cout<<endl;
        if(total_correct_combinations == 1)
        {
            cout<<"correct"<<endl;
        }
        else
        {
            cout<<"incorrect"<<endl;
        }
    }
    else 
    {
        cout<<total_correct_combinations<<" "<<"correct"<<endl;
        cout<<total_incorrect_combinations<<" "<<"incorrect"<<endl;
    }
    
    
    return 0;
}
