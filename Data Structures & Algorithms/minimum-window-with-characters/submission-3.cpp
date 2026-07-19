class Solution {
public:
    string minWindow(string s, string t) {
        if(s == t) return s;
        if(s.size() < t.size()) return "";

        string ans = "";
        int len = INT_MAX;
        int left = 0;

        unordered_map<char, int> countT, countS;
        for(char ch: t) countT[ch]++;

        int matched = 0;
        for(int i = 0; i < s.size(); i++){
            if(countT.find(s[i]) != countT.end()){
                countS[s[i]]++;

                if(countS[s[i]] == countT[s[i]]) matched++;
            }

                while(countT.size() == matched){
                    if(i - left + 1 < len){
                        len = i - left + 1;
                        ans = s.substr(left, i - left + 1);
                    }

                    if(countS.find(s[left]) != countS.end()){
                        if(countS[s[left]] == countT[s[left]]) matched--;
                        countS[s[left]]--;
                        
                        if(countS[s[left]] == 0) countS.erase(s[left]);
                    }
                    left++;
                }
        }
        return ans;
    }
};
