
// Q : make your own atoi c function
#include <bits/stdc++.h>

using namespace std;

int custom_atoi(char *str)
{
    int res = 0;
    int sign = 1, i = 0;
    if(str == nullptr) return 0;
    if(str[0] == '-')
    {
        sign = -1;
        i++;
    }
    for( ; str[i] != '\0'; i++) {
        res = res*10 + str[i] - '0'; 
    }

    return sign*res;
}

int main() { 
    char* num_str = "123";
    cout<<custom_atoi(num_str);
    return 0;
}
