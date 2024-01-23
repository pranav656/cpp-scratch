// Hackerrank
// Regex pattern for 10a10.2015452254
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <regex>

using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string input_string;
    getline(cin, input_string);
    std::regex expression(".*\\d{2}\\D\\d{2}\\D\\d{4}.*");
    if(regex_match(input_string, expression))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}
