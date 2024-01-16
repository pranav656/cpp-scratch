// LC128 - Longest Consequtive Sequnce
// O(n) time solution with O(n) memory
// For each number, check if it's predecessor
// already exists in the hash set, if not
// mark it as a start of the sequence and
// search the hash set till the consequtive 
// elements are not found. Track the 
// max sequence length as they are found.
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int longest_sequence_length = 0;
        for(auto &num : nums)
        {
            if(numset.count(num-1) == 0)
            {
                int search = num+1;
                int curr_seq_length = 1;
                while(numset.count(search) != 0)
                {
                    search++;
                    curr_seq_length++;
                }
                longest_sequence_length = max(curr_seq_length, longest_sequence_length);
            }
        }
        return longest_sequence_length;
    }
};
