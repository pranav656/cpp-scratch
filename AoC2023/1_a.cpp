#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    int first_num = INT_MAX, second_num=-1;
    int sum = 0;
    string line;
    vector<int> nums;
    int j = 0;
    while(cin>>line)
    {
        for(int i = 0; i<line.size(); i++)
        {
            if(line[i] >= '0' && line[i]<= '9')
            {
                if(i<first_num)
                {
                    first_num = i;
                }
                if(i>second_num)
                {
                    second_num = i;
                }
            }
        }
        //cout<<"fn:"<<first_num<<"sn:"<<second_num<<endl;
        int num = (line[first_num]-'0')*10 + (line[second_num]-'0');
        sum += num;
        j++;
        first_num = INT_MAX, second_num=-1;
        //cout<<num<<endl;
    }
    cout<<"sum:"<<sum<<endl;
}
