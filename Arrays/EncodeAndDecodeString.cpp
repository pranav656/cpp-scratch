// LC271 - Encode and decode a vector of strings
// Straightforward, store the end positions in a vector and
// use it for decoding. 
class Solution {
public:
    vector<int> positions;
    
    string encode(vector<string>& strs) {
        positions.clear();
        int curr_pos = 0;
        string encoded_string;
        positions.push_back(curr_pos);
        for(auto str:strs)
        {
            encoded_string += str;
            curr_pos += str.size();
            positions.push_back(curr_pos);
        }
        return encoded_string;
    }

    vector<string> decode(string s) {
        vector<string> decoded_vector;
        for(int i = 0; i<positions.size()-1; i++)
        {
            int start = positions[i];
            int end = positions[i+1];
            string decoded_string = s.substr(start, end-start);
            decoded_vector.push_back(decoded_string);
        }
        return decoded_vector;
    }
};
