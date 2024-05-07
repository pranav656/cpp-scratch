class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> sol;
        for(int i = 1; i<= searchWord.size(); i++) {
            string search_substr = searchWord.substr(0, i);
            set<string> suggestions;
            vector<string> sugg_i;
            for(string& p : products)
            {
                if(p.size() >= search_substr.size())
                {
                    if(p.substr(0, search_substr.size()) == search_substr)
                    {
                        suggestions.insert(p);
                    }
                }
            }
            auto it = suggestions.begin();
            for(int j = 0; j<min(int(suggestions.size()), 3); j++)
            {
                sugg_i.push_back(*it);
                it = next(it);
            }
            sol.push_back(sugg_i);
        }
        return sol;
    }
};
