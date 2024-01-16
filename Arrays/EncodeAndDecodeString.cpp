class Solution {
public:
    vector<int> positions;
    
    string encode(vector<string>& strs) {
        positions.clear();
        int curr_pos = 0;
        string encoded_string;
        positions.push_back(curr_pos);
        cout<<curr_pos<<endl;
        for(auto str:strs)
        {
            encoded_string += str;
            curr_pos += str.size();
            positions.push_back(curr_pos);
            cout<<curr_pos<<endl;
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_vector;
        cout<<s<<endl;
        for(int i = 0; i<positions.size()-1; i++)
        {
            int start = positions[i];
            int end = positions[i+1];
            string decoded_string = s.substr(start, end-start);
            cout<<decoded_string;
            decoded_vector.push_back(decoded_string);
        }
        return decoded_vector;
    }
};
