class Solution {
public:
    int characterReplacement(string s, int k) {
       int ans = 0;
       unordered_set<char> charset;

       for(char ch: s) charset.insert(ch);

       for(char ch: charset){
        int count = 0, l = 0;

        for(int r = 0; r < s.size(); r++){
            if(s[r] == ch) count++;

            while((r - l + 1) - count > k){
                if(s[l] == ch) count--;
                l++;
            }

            ans = max(ans, r - l + 1);
        }
       } 

       return ans;
    }
};
