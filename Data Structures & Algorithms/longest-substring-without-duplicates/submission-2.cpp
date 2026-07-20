class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxlen = 0;
        int left = 0;

        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch]++;

            while(mp[ch] > 1){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }

            maxlen = max(maxlen, i - left + 1);
        }

        return maxlen;
    }
};
