class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> cs(26, 0), ts(26, 0);

        for(char ch: s) cs[ch - 'a']++;
        for(char ch: t) ts[ch - 'a']++;

        return cs == ts;
    }
};
