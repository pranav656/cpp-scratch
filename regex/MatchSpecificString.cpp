// Hackerrank - Match specific string hackerrank
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <regex>

using namespace std;


int main() {
    string input_string;
    getline(cin, input_string);
        
    regex str_regex("hackerrank");
    auto words_begin = sregex_iterator(input_string.begin(), input_string.end(), str_regex);
    auto words_end = sregex_iterator();
    
    cout<< "Number of matches : "<<distance(words_begin, words_end);
    return 0;
}
