// https://open.kattis.com/contests/yostym/problems/anewalphabet

#include <bits/stdc++.h>

using namespace std;

array<string, 26> translations =
{"@", "8", "(", "|)", "3", "#", "6", "[-]",
    "|", "_|", "|<", "1", "[]\\/[]", "[]\\[]",
    "0", "|D", "(,)", "|Z", "$", "']['", "|_|",
    "\\/","\\/\\/", "}{", "`/", "2"};

int main()
{
    string str;
    getline(cin, str);
    transform(str.begin(), str.end(), str.begin(), 
    ::tolower); 
    string o_str;
    for(int i = 0; i<str.size(); i++)
    {
        if(str[i] >='a' && str[i] <= 'z')
        {
           for(char c : translations[str[i] - 'a'])
           {
               o_str.push_back(c);
           }
        }
        else
        {
          o_str.push_back(str[i]);
        }
    }
    cout<<o_str<<endl;
    
    return 0;
}
