#include <bits/stdc++.h>

using namespace std;
using ll = long long;

char get_symbol(vector<string>& chars, int i, int j)
{
    if (i < 0 || i >= chars.size() || j < 0 || j >= chars[0].size())
        return '.';
    return chars[i][j];
}

int get_number(vector<string>& chars, int i, int j)
{
    // variables to find the number
    int l = 0;
    int r = 0;
    while (j - l >= 0 && isdigit(chars[i][j - l])) {
        l++;
    }
    while (j + r < chars[0].size() && isdigit(chars[i][j + r])) {
        r++;
    }
    // +1 because that's the point where
    // the loop breaks
    return stoi(chars[i].substr(j - l + 1, r + l - 1));
}
// search for numbers and return the neighbouring numbers as
// a vector
vector<int> search_nums(vector<string>& chars, int i, int j)
{
    vector<int> nums;
    char up = get_symbol(chars, i - 1, j);
    char up_left = get_symbol(chars, i - 1, j - 1);
    char up_right = get_symbol(chars, i - 1, j + 1);
    char down = get_symbol(chars, i + 1, j);
    char down_left = get_symbol(chars, i + 1, j - 1);
    char down_right = get_symbol(chars, i + 1, j + 1);
    char left = get_symbol(chars, i, j - 1);
    char right = get_symbol(chars, i, j + 1);
    if (isdigit(up_left) || isdigit(up_right)) {

        /*
        sequence like this
          1 2 3
            *
        */
        if (isdigit(up)) {
            nums.push_back(get_number(chars, i - 1, j));
        }
        else {
            /*
            sequence like this
                1 . 3 
                  *
                */
            if (isdigit(up_left)) {
                nums.push_back(get_number(chars, i - 1, j - 1));
            }
            if (isdigit(up_right)) {
                nums.push_back(get_number(chars, i - 1, j + 1));
            }
        }
    }
    else if (isdigit(up)) {
        nums.push_back(get_number(chars, i - 1, j));
    }
    if (isdigit(left)) {
        nums.push_back(get_number(chars, i, j - 1));
    }
    if (isdigit(right)) {
        nums.push_back(get_number(chars, i, j + 1));
    }
    // same logic as up
    if (isdigit(down_left) || isdigit(down_right)) {
        if (isdigit(down)) {
            nums.push_back(get_number(chars, i + 1, j));
        }
        else {
            if (isdigit(down_left)) {
                nums.push_back(get_number(chars, i + 1, j - 1));
            }
            if (isdigit(down_right)) {
                nums.push_back(get_number(chars, i + 1, j + 1));
            }
        }
    }
    else if (isdigit(down)) {
        nums.push_back(get_number(chars, i + 1, j));
    }
    return nums;
}

int main()
{
    ll ans = 0;
    vector<string> chars;
    string input;
    while (getline(cin, input)) {
        chars.push_back(input);
    }
    int r = chars.size(), c = chars[0].size();
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (chars[i][j] == '*') {
                vector<int> nums = search_nums(chars, i, j);
                if (nums.size() == 2) {
                    ans += nums[0] * nums[1];
                }
            }
        }
    }
    cout << ans << endl;
}
