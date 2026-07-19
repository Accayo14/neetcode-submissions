class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;

        for(string str: strs){
            string ogstr = str;
            sort(str.begin(), str.end());

            mp[str].push_back(ogstr);
        }

        vector<vector<string>> ans;

        for(auto [str, words]: mp){
            ans.push_back(words);
        }

        return ans;
    }
};
