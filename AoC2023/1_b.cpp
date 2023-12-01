#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    int sum = 0;
    string line;
    vector<int> nums;
    vector<int> found_nums;
    array<string, 9> str_nums = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
    while (cin >> line) {
        for (int i = 0; i < line.size(); i++) {
            if (line[i] >= '0' && line[i] <= '9') {
                found_nums.push_back(line[i] - '0');
            }
            for (int j = 0; j <= 8; j++) {
                if (i + str_nums[j].size() <= line.size()) {
                    if (line.substr(i, str_nums[j].size()) == str_nums[j]) {
                        //cout<<str_nums[j]<<endl;
                        found_nums.push_back(j + 1);
                    }
                }
            }
        }
        int num = (found_nums[0]) * 10 + (found_nums[found_nums.size() - 1]);
        found_nums.clear();
        //cout<<num<<endl;
        sum += num;
    }
    cout << "sum:" << sum << endl;
    return 0;
}
